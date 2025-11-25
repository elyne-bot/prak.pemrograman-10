#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Fungsi Pencarian Sekuensial 
int cari_sekuensial(int data[], int s, int cari) {
    bool ketemu;
    int i = 0;

    ketemu = false;
    while ((i < s) && !(ketemu)) {
        ketemu = (data[i++] == cari);
    }

    if (ketemu) {
        return i;          
    } else {
        return -1 * i;     
    }
}

// Selection Sort untuk mengurutkan data 
void selection_sort(int data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        int temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
}

int main() {
    const int N = 1000;
    int data[N];
    int cari[10];

    srand(time(0));

    cout << "Membuat 1000 data acak\n";
    for (int i = 0; i < N; i++) {
        data[i] = rand() % 1000;
    }

   
    cout << "\nMasukkan 10 indeks yang ingin dicari (0–999):\n";
    for (int i = 0; i < 10; i++) {
        int idx;
        cout << "Indeks ke-" << i + 1 << ": ";
        cin >> idx;

        if (idx >= 0 && idx < N)
            cari[i] = data[idx];
        else
            cari[i] = -1;  
    }

    cout << "\n sebelum sorting\n";
    for (int i = 0; i < 10; i++) {
        int hasil = cari_sekuensial(data, N, cari[i]);
        cout << "Mencari " << cari[i]
             << " | Hasil = " << hasil
             << " | Langkah = " << abs(hasil)
             << endl;
    }

   //mengurutkan data
    cout << "\nMengurutkan data dengan Selection Sort\n";
    selection_sort(data, N);

    cout << "\n setelah sorting\n";
    for (int i = 0; i < 10; i++) {
        int hasil = cari_sekuensial(data, N, cari[i]);
        cout << "Mencari " << cari[i]
             << " | Hasil = " << hasil
             << " | Langkah = " << abs(hasil)
             << endl;
    }

    return 0;
}


