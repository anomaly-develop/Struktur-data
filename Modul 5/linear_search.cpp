#include <iostream>
using namespace std;

int linearSearch(int data[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int data[] = {7, 14, 21, 28, 35, 42, 49, 56, 63, 70};
    int n = 10;
    int target = 49;

    int hasil = linearSearch(data, n, target);
    
    if (hasil != -1) {
        cout << "Elemen ditemukan pada indeks : " << hasil << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

}