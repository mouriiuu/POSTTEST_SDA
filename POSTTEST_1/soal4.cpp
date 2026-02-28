// · gunakan pointer dalam fungsi untuk melakukan pertukaran nilai.
// · Uji fungsi tersebut dengan dua nilai input dan tampilkan hasil sebelum dan sesudah pertukaran.

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// jdi ini cara kerja pointer penukarannya si temp ini bakal nyimpan nilai dari a agar dia ga hilang, kemudian pointer a bakal di isi
// dengan nilai dari b, dan terakhir pointer b bakal di isi dengan nilai yang di simpan di temp tadi, mirip2 kaya soal no 3

int main() {
    int a, b;
    cout << "Masukkan nilai a : ";
    cin >> a;
    cout << "Masukkan nilai b : ";
    cin >> b;

    cout << "Sebelum pertukaran : " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    swap(&a, &b);

    cout << "Setelah pertukaran : " << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}