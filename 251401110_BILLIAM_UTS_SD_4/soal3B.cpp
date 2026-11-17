#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

void tambahpelanggan(string nama) {
    Node* baru = new Node{nama, nullptr};
    if (front == nullptr) {
        front = baru;
        rear = baru;
        return;
    }
    rear->next = baru;
    rear = baru;
}

void layani() {
    if (front == nullptr) {
        cout << "antrean kosong" << endl;
        return;
    }
    Node* hapus = front;
    cout << "melayani pelanggan: " << front->nama << endl;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }
}

void tampilkandepan() {
    if (front == nullptr) {
        cout << "antrean kosong" << endl;
        return;
    }
    cout << "pelanggan paling depan: " << front->nama << endl;
}

void tampilkanbelakang() {
    if (rear == nullptr) {
        cout << "antrean kosong" << endl;
        return;
    }
    cout << "pelanggan paling belakang: " << rear->nama << endl;
}

int jumlahantrean() {
    int jumlah = 0;
    Node* temp = front;
    while (temp != nullptr) {
        jumlah++;
        temp = temp->next;
    }
    return jumlah;
}

void tampilkan() {
    if (front == nullptr) {
        cout << "antrean kosong" << endl;
        return;
    }
    Node* temp = front;
    cout << "isi antrean: ";
    while (temp != nullptr) {
        cout << temp->nama;
        if (temp->next) cout << ", ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int pilih;
    string nama;

    do {
        cout << "1. tambah pelanggan" << endl;
        cout << "2. layani pelanggan" << endl;
        cout << "3. tampilkan pelanggan paling depan" << endl;
        cout << "4. tampilkan pelanggan paling belakang" << endl;
        cout << "5. jumlah pelanggan menunggu" << endl;
        cout << "6. tampilkan antrean pelanggan" << endl;
        cout << "0. keluar" << endl;
        cout << "pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "nama pelanggan: ";
                cin >> nama;
                tambahpelanggan(nama);
                break;
            case 2:
                layani();
                break;
            case 3:
                tampilkandepan();
                break;
            case 4:
                tampilkanbelakang();
                break;
            case 5:
                cout << "jumlah pelanggan menunggu: " << jumlahantrean() << endl;
                break;
            case 6:
                tampilkan();
                break;
        }
    } while (pilih != 0);
}