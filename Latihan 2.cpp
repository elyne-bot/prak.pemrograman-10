#include <iostream>
using namespace std;

int main() {
	const int N = 10;
	int data[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// ---- Tampilkan data awal
	cout << "Data awal:\n";
	for (int i = 0; i < N; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	// ---- Selection Sort untuk mengurutkan data
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

	// ---- Tampilkan data setelah diurutkan
	cout << "\nData setelah diurutkan:\n";
	for (int i = 0; i < N; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	int palingKecil = data[0];
	int palingBesar = data[N - 1];

	cout << "\nPencarian Biner\n";

	// ---- Cari paling kecil
	int low = 0, high = N - 1, langkah = 0, ketemu = -1;
	while (low <= high) {
		langkah++;
		int mid = (low + high) / 2;

		if (data[mid] == palingKecil) {
			ketemu = mid;
			break;
		} else if (palingKecil < data[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << "Paling kecil (" << palingKecil << ") ditemukan di indeks "
	     << ketemu << " | Langkah: " << langkah << endl;

	// Cari paling besar
	low = 0;
	high = N - 1;
	langkah = 0;
	ketemu = -1;

	while (low <= high) {
		langkah++;
		int mid = (low + high) / 2;

		if (data[mid] == palingBesar) {
			ketemu = mid;
			break;
		} else if (palingBesar < data[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	cout << "Paling besar (" << palingBesar << ") ditemukan di indeks "
	     << ketemu << " | Langkah: " << langkah << endl;

	return 0;
}
