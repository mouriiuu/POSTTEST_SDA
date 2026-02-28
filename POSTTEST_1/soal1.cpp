//  Implementasikan fungsi FindMin di C++ menggunakan array bertipe integer dengan 8 elemen, diisi dengan bilangan Fibonacci (1, 1, 2, 3, 5, 8, 13, 21).

#include <iostream>
using namespace std;

int FindMin(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int data[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    int minimum = FindMin(data, 8);

    cout << "Nilai minimum dalam array adalah : " << minimum << endl;

    return 0;
}

// Hitung Tmin(n) dan Tmax(n) secara manual seperti contoh pada modul (tabel pseudocode + cost)

// procedure FindMin(A : array of n elemen)   Cost C1
//       min ← A[0]                           Cost C2
//       for i ← 1 to n-1 do                  Cost C3
//           if A[i] < min then               Cost C4
//               min ← A[i]                   Cost C5
//           end if                           Cost C6
//       end for                              Cost C7
//       return min                           Cost C8
//   end procedure                            Cost C9

// sesuai dengan table pseudocode + cost di modul, maka tmin & tmax di hitung sebagai berikut

// Tmin(n) = C1 + C2 + C3.n + C4.(n-1) + 0 + C6.(n-1) + C7.n + C8 + C9
        // = C1 + C2 + C3.n + C4.n - C4 + C6.n - C6 + C7.n + C8 + C9
        // = (C3 + C4 + C6 + C7).n + (C1 + C2 + C8 + C9 - C4 - C6)
        // = (1 + 1 + 1 + 1).n + (1 + 1 + 1 + 1 - 1 - 1)
        // = 4n + 2

// Tmax(n) = C1 + C2 + C3.n + C4.(n-1) + C5.(n-1) + C6.(n-1) + C7.n + C8 + C9
        // = C1 + C2 + C3.n + C4.n - C4 + C5.n - C5 + C6.n - C6 + C7.n + C8 + C9
        // = (C3 + C4 + C5 + C6 + C7).n + (C1 + C2 + C8 + C9 - C4 - C5 - C6)
        // = (1 + 1 + 1 + 1 + 1).n + (1 + 1 + 1 + 1 - 1 - 1 - 1)
        // = 5n + 2

// dari yang kita liat tmin = 4n + 2 dan tmax = 5n + 2, yang di mana keduanya memiliki kompleksitas O(n) 
// karna 4n dan 5n merupakan fungsi linear

// Tmin(n)  = O(n) Best Case
// Tmax(n)  = O(n) Worst Case

// karena Kompleksitas O(1) berarti waktu pelaksanaan algoritma adalah tetap, tidak
// bergantung pada ukuran masukan.