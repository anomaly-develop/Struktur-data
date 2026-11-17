#include <iostream>
using namespace std;

int main() {
    int nilai[5][4] = { {60, 65, 70, 65},{60, 70, 80, 90},{80, 82, 84, 86},{90, 80, 70, 60},{95, 60, 75, 85}
    };
    float rata[5];
    float total, tertinggi, terendah;
    int tertinggi1 = 0, terendah1 = 0;
    int jumlah = 0;

    for (int i = 0; i < 5; i++) {
        total = 0;
        for (int j = 0; j < 4; j++) {
            total += nilai[i][j];
        }
        rata[i] = total / 4;
    }
    for (int i = 0; i < 5; i++) {
        cout << "rata-rata mahasiswa ke-" << i + 1 << " : " << rata[i] << endl;
    }

    tertinggi = rata[0];
    terendah = rata[0];

    for (int i = 1; i < 5; i++) {
        if (rata[i] > tertinggi) {
            tertinggi = rata[i];
            tertinggi1 = i;
        }
        if (rata[i] < terendah) {
            terendah = rata[i];
            terendah1 = i;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (rata[i] >= 75) {
            jumlah++;
        }
    }

    cout << "rata-rata tertinggi : " << tertinggi << " (mahasiswa ke-" << tertinggi1 + 1 << ")" << endl;
    cout << "rata-rata terendah : " << terendah << " (mahasiswa ke-" << terendah1 + 1 << ")" << endl;
    cout << "jumlah mahasiswa dengan rata-rata minimal 75 : " << jumlah << endl;
}