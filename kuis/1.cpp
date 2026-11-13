#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nim;
    string nama;
    int nilai;
    Node* next;
};

Node* head = nullptr;

void tambahBelakang(string nim, string nama, int nilai) {
    Node* baru = new Node{nim, nama, nilai, nullptr};
    if (!head) { head = baru; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = baru;
}

void tampilkan() {
    Node* temp = head;
    cout << "NIM\t\tNama\t\tNilai" << endl;
    while (temp) {
        cout << temp->nim << "\t" << temp->nama << "\t" << temp->nilai << endl;
        temp = temp->next;
    }
}

void insertionSort() {
    if (!head || !head->next) return;

    Node* sorted = nullptr;
    Node* current = head;

    while (current) {
        Node* next = current->next;
        if (!sorted || current->nilai <= sorted->nilai) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->nilai < current->nilai) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}

int linearSearchNIM(string target) {
    Node* temp = head;
    int index = 0;
    while (temp) {
        if (temp->nim == target) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

int binarySearchNilai(int data[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    int* nilaiArray = new int[n];

    cout << "Masukkan data mahasiswa (NIM Nama Nilai):" << endl;
    for (int i = 0; i < n; i++) {
        string nim, nama;
        int nilai;
        cout << "Mahasiswa ke-" << i + 1 << ": ";
        cin >> nim >> nama >> nilai;
        tambahBelakang(nim, nama, nilai);
        nilaiArray[i] = nilai;
    }

    cout << "\nData awal:" << endl;
    tampilkan();

    insertionSort();

    cout << "\nData setelah diurutkan (nilai terkecil -> terbesar):" << endl;
    tampilkan();

    Node* temp = head;
    for (int i = 0; i < n; i++) {
        nilaiArray[i] = temp->nilai;
        temp = temp->next;
    }

    string nimCari;
    cout << "\nMasukkan NIM yang dicari: ";
    cin >> nimCari;

    int hasilLinear = linearSearchNIM(nimCari);
    if (hasilLinear != -1) {
        cout << "NIM ditemukan pada urutan ke-" << hasilLinear + 1 << endl;
    } else {
        cout << "NIM tidak ditemukan" << endl;
    }

    int nilaiCari;
    cout << "Masukkan nilai yang dicari: ";
    cin >> nilaiCari;

    int hasilBinary = binarySearchNilai(nilaiArray, n, nilaiCari);
    if (hasilBinary != -1) {
        cout << "Nilai ditemukan pada indeks : " << hasilBinary << endl;
    } else {
        cout << "Nilai tidak ditemukan" << endl;
    }

    delete[] nilaiArray;

    return 0;
}