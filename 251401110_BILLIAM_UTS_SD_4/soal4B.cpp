#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

void tambah(Node*& root, int angka) {
    if (root == NULL) {
        root = new Node;
        root->data = angka;
        root->kiri = NULL;
        root->kanan = NULL;
    } else if (angka < root->data) {
        tambah(root->kiri, angka);
    } else if (angka > root->data) {
        tambah(root->kanan, angka);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void tampilRentang(Node* root, int bawah, int atas) {
    if (root != NULL) {
        tampilRentang(root->kiri, bawah, atas);
        if (root->data >= bawah && root->data <= atas) {
            cout << root->data << " ";
        }
        tampilRentang(root->kanan, bawah, atas);
    }
}

bool cari(Node* root, int angka) {
    if (root == NULL) {
        return false;
    }
    if (root->data == angka) {
        return true;
    } else if (angka < root->data) {
        return cari(root->kiri, angka);
    } else {
        return cari(root->kanan, angka);
    }
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (-1 untuk berhenti) : ";
    cin >> angka;

    while (angka != -1) {
        tambah(root, angka);
        cin >> angka;
    }

    int bawah, atas;
    cout << "batas bawah : ";
    cin >> bawah;
    cout << "batas atas : ";
    cin >> atas;

    cout << "nilai antara " << bawah << " dan " << atas << " : ";
    tampilRentang(root, bawah, atas);
    cout << endl;

    cout << "cari nilai : ";
    cin >> angka;

    if (cari(root, angka)) {
        cout << "nilai " << angka << " terdapat di BST" << endl;
    } else {
        cout << "nilai " << angka << " tidak terdapat di BST" << endl;
    }
}