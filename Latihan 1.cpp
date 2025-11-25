#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int data[N] = {7, 9, 8, 6, 10, 3, 4, 5, 2, 1};

    // Tampilkan data awal
    cout << "Data awal:\n";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Selection Sort untuk mengurutkan data
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }

    // Tampilkan data setelah diurutkan
    cout << "\nData setelah diurutkan:\n";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int palingKecil = data[0];
    int palingBesar = data[N - 1];

    cout << "\nsekuensial\n";

    // Cari paling kecil
    int langkah = 0, ketemu = -1;
    for (int i = 0; i < N; i++) {
        langkah++;
        if (data[i] == palingKecil) {
            ketemu = i;
            break;
        }
    }
    cout << "Paling kecil (" << palingKecil << ") ditemukan di indeks "
         << ketemu << " | Langkah: " << langkah << endl;

    // Cari paling besar
    langkah = 0;
    ketemu = -1;
    for (int i = 0; i < N; i++) {
        langkah++;
        if (data[i] == palingBesar) {
            ketemu = i;
            break;
        }
    }
    cout << "Paling besar (" << palingBesar << ") ditemukan di indeks "
         << ketemu << " | Langkah: " << langkah << endl;

    return 0;
}
