#include <iostream>
using namespace std;

int binarySearch(int data[], int n, int target) {
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
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[100];
    for (int i = 0; i < n; i++) {
        cout << "Nilai mahasiswa ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int target;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    int hasil = binarySearch(data, n, target);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}