#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 20

struct Data {
    int key;
    string nama;
    bool occupied;
    bool deleted;
};

Data table[TABLE_SIZE];

int hash1(int key) {
    return key % 20;
}

int hash2(int key) {
    int step = 19 - (key % 19);
    while (step % 2 == 0 || step % 5 == 0) {
        step++;
        if (step >= TABLE_SIZE) step = 1;
    }
    return step;
}

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1;
        table[i].nama = "";
        table[i].occupied = false;
        table[i].deleted = false;
    }
}

void insert(int key, string nama) {
    int index = hash1(key);
    int step = hash2(key);
    int count = 0;

    while (count < TABLE_SIZE) {
        if (!table[index].occupied || table[index].deleted) {
            table[index].key = key;
            table[index].nama = nama;
            table[index].occupied = true;
            table[index].deleted = false;
            cout << "Insert berhasil pada index " << index << endl;
            return;
        }

        if (table[index].key == key && !table[index].deleted) {
            cout << "Data dengan key " << key << " sudah ada!" << endl;
            return;
        }

        cout << "Collision di index " << index << ", ";
        index = (index + step) % TABLE_SIZE;
        cout << "pindah ke index " << index << endl;
        count++;
    }
    cout << "Tabel penuh!" << endl;
}

int search(int key) {
    int index = hash1(key);
    int step = hash2(key);
    int count = 0;

    while (count < TABLE_SIZE) {
        if (!table[index].occupied && !table[index].deleted) {
            return -1;
        }

        if (table[index].key == key && !table[index].deleted) {
            return index;
        }

        index = (index + step) % TABLE_SIZE;
        count++;
    }
    return -1;
}

void remove(int key) {
    int index = search(key);

    if (index == -1) {
        cout << "Data dengan key " << key << " tidak ditemukan!" << endl;
        return;
    }

    table[index].deleted = true;
    table[index].nama = "";
    cout << "Data dengan key " << key << " berhasil dihapus dari index " << index << endl;
}

void display() {
    cout << "\n Isi Hash Table " << endl;
    cout << "Index\tKey\tNama\tStatus" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << "\t";
        if (table[i].occupied && !table[i].deleted) {
            cout << table[i].key << "\t" << table[i].nama << "\tTerisi";
        } else if (table[i].deleted) {
            cout << "-\t-\tDeleted";
        } else {
            cout << "-\t-\tKosong";
        }
        cout << endl;
    }
}

int main() {
    initTable();

    cout << "Insert Data Mahasiswa " << endl;
    insert(2201, "Andi");
    insert(2202, "Budi");
    insert(2205, "Citra");
    insert(2221, "Dewi");
    insert(2241, "Eka");
    insert(2210, "Fajar");
    insert(2261, "Gilang");
    insert(2230, "Hani");
    insert(2250, "Indra");
    insert(2270, "Joko");
    insert(2290, "Kartika");
    insert(2215, "Ludi");

    display();

    cout << "\nSearch Data " << endl;
    int cari;
    cout << "Masukkan NIM yang dicari: ";
    cin >> cari;

    int hasil = search(cari);
    if (hasil != -1) {
        cout << "Data ditemukan pada index " << hasil
            << " : " << table[hasil].nama << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    cout << "\nRemove Data " << endl;
    int hapus;
    cout << "Masukkan NIM yang dihapus: ";
    cin >> hapus;
    remove(hapus);

    display();

    cout << "\nSearch Setelah Remove :" << endl;
    cout << "Masukkan NIM yang dicari: ";
    cin >> cari;

    hasil = search(cari);
    if (hasil != -1) {
        cout << "Data ditemukan pada index " << hasil
            << " : " << table[hasil].nama << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}