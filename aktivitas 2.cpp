#include <iostream>
using namespace std;

// Fungsi pencarian biner sesuai modul
int cari_biner(int data[], int s, int cari) {
    int a = 0, b = s - 1;
    int t, langkah = 0;
    bool ketemu = false;

    do {
        t = (a + b) / 2;

        if (data[t] == cari) {
            ketemu = true;
        } else {
            if (data[t] > cari) {
                b = t - 1;
            } else {
                a = t + 1;
            }
        }

        langkah++;

    } while ((a <= b) && !ketemu);

    return ketemu ? langkah : -1 * langkah;
}

int main() {
    const int N = 1000;
    int data[N];
    int cari[10];

    // Isi array dengan data terurut 0–999
    for (int i = 0; i < N; i++) {
        data[i] = i;
    }

    // Input 10 nilai yang ingin dicari
    cout << "Masukkan 10 nilai (0–999) yang ingin dicari:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Data ke-" << (i + 1) << ": ";
        cin >> cari[i];
    }

    // Pencarian biner
    cout << "\n HASIL PENCARIAN BINER \n";
    for (int i = 0; i < 10; i++) {
        int hasil = cari_biner(data, N, cari[i]);

        cout << "Mencari " << cari[i]
             << " | Langkah = " << abs(hasil)
             << " | Status = "
             << (hasil > 0 ? "Ditemukan" : "Tidak ditemukan")
             << endl;
    }

    return 0;
}

