#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahBelakang(int v) {
    Node* baru = new Node{v, nullptr};
    if (!head) { head = baru; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = baru;
}

void tampilkan() {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << ", ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusSetelah(int v) {
    Node* temp = head;
    while (temp && temp->data != v) temp = temp->next;

    if (!temp) {
        cout << "nilai " << v << " tidak ditemukan" << endl;
        return;
    }
    if (!temp->next) {
        cout << "nilai " << v << " tidak memiliki node setelahnya" << endl;
        return;
    }

    Node* hapus = temp->next;
    temp->next = hapus->next;
    delete hapus;
}

void balik() {
    Node* prev = nullptr;
    Node* temp = head;
    Node* next;

    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

int main() {
    int angka, n, cari;

    cout << "jumlah data : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "data ke-" << i + 1 << ": ";
        cin >> angka;
        tambahBelakang(angka);
    }

    cout << "Data awal: ";
    tampilkan();

    cout << "Hapus node setelah nilai: ";
    cin >> cari;
    hapusSetelah(cari);
    cout << "Setelah dihapus: ";
    tampilkan();

    balik();
    cout << "Setelah dibalik: ";
    tampilkan();

    cout << "Hapus node setelah nilai: ";
    cin >> cari;
    hapusSetelah(cari);
    cout << "Setelah hapus: ";
    tampilkan();

}