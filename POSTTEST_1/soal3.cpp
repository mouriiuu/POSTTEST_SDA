// • Deklarasikan array berisi 7 elemen yang diisi dengan bilangan prima (2, 3, 5, 7, 11, 13, 17).
// • Buat fungsi reverseArray(int* arr, int n) menggunakan pointer (bukan indeks) untuk membalik urutan array.
// • Tampilkan array sebelum dan sesudah dibalik.
// Tampilkan pula alamat memori setiap elemen menggunakan pointer.

#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - 1 - i);
        *(arr + n - 1 - i) = temp;
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik : " << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Bilangan ke-" << i << ": " << prima[i] << " (Alamat: " << &prima[i] << ")" << endl;
    }

    reverseArray(prima, 7);

    cout << "\nArray setelah dibalik : " << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Bilangan ke-" << i << ": " << prima[i] << " (Alamat: " << &prima[i] << ")" << endl;
    }
    return 0;
}