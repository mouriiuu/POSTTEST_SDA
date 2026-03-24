#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

void swapKereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string inputString(string pesan) {
    string data;
    do {
        cout << pesan;
        getline(cin, data);
        if (data.empty())
            cout << "Tidak boleh kosong!\n";
    } while (data.empty());
    return data;
}

int inputAngka(string pesan) {
    int x;
    cout << pesan;
    while (!(cin >> x)) {
        cout << "Input harus angka! Coba lagi : ";
        clearInput();
    }
    clearInput();
    return x;
}

void tampilkan(Kereta* arr, int n) {
    if (n == 0) {
        cout << "\nData kosong\n";
        return;
    }

    cout << "\n=== JADWAL KERETA ===\n";
    for (int i = 0; i < n; i++) {
        Kereta* p = (arr + i);
        cout << p->nomor << " | " << p->nama << " | "
             << p->asal << " -> " << p->tujuan
             << " | Rp." << p->harga << endl;
    }
}

void tambahKereta(Kereta* arr, int &n) {
    if (n >= 100) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\nTambah Data Kereta:\n";

    (arr + n)->nomor = inputAngka("Nomor: ");
    (arr + n)->nama = inputString("Nama: ");
    (arr + n)->asal = inputString("Asal: ");
    (arr + n)->tujuan = inputString("Tujuan: ");
    (arr + n)->harga = inputAngka("Harga: ");

    n++;
    cout << "Data berhasil ditambahkan!\n";
}

void linearSearch(Kereta* arr, int n, string asal, string tujuan) {
    if (n == 0) {
        cout << "Data kosong\n";
        return;
    }

    bool ketemu = false;

    cout << "\n=== PROSES LINEAR SEARCH ===\n";

    for (int i = 0; i < n; i++) {
        cout << "Iterasi ke-" << i + 1 << endl;
        cout << "Cek : " << (arr + i)->asal << " -> " << (arr + i)->tujuan << endl;

        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Hasil: DITEMUKAN -> " << (arr + i)->nama << endl;
            ketemu = true;
        } else {
            cout << "Hasil : Tidak cocok\n";
        }
        cout << endl;
    }

    if (!ketemu)
        cout << "Data tidak ditemukan.\n";
}

// jadi linear search ini proses iterasi dilakukan dengan dia ngecek data satu per satu
// secara berurutan dari indeks pertama hingga terakhir, nah di setiap iterasi, program ini bakal
// Ngebandingin nilai yang dicari dalam kasus ini itu asal dan tujuan, dengan data pada indeks 
// saat itu. Jika cocok, maka data dianggap ditemukan dan ditampilkan dan jika tidak, 
// program bakal lanjut ke elemen berikutnya, proses ini terus berjalan sampai seluruh data 
// dicek atau sampai data yang dicari ditemukan atau habis

int jumpSearch(Kereta* arr, int n, int target) {
    if (n == 0) return -1;

    int step = sqrt(n);
    int prev = 0;

    cout << "\n=== PROSES JUMP SEARCH ===\n";

    while (step < n && (arr + step - 1)->nomor < target) {
        cout << "Lompat ke index " << step - 1 
             << " (nomor : " << (arr + step - 1)->nomor << ")\n";

        prev = step;
        step += sqrt(n);

        if (prev >= n)
            return -1;
    }

    cout << "\nLinear Search dalam blok :\n";

    for (int i = prev; i < step && i < n; i++) {
        cout << "Cek index " << i 
             << " (nomor : " << (arr + i)->nomor << ")\n";

        if ((arr + i)->nomor == target)
            return i;
    }

    return -1;
}

void merge(Kereta* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + l + i);

    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if ((L + i)->nama < (R + j)->nama) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = *(L + i);
        i++; k++;
    }

    while (j < n2) {
        *(arr + k) = *(R + j);
        j++; k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Kereta* arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta* arr, int n) {
    if (n == 0) return;

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min)->harga)
                min = j;
        }
        swapKereta((arr + i), (arr + min));
    }
}

int main() {
    Kereta data[100] = {
        {101, "Argo Bromo", "Jakarta", "Surabaya", 500000},
        {102, "Taksaka", "Jakarta", "Yogyakarta", 400000},
        {103, "Malioboro", "Yogyakarta", "Malang", 300000}
    };

    int n = 3;
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampilkan\n";
        cout << "2. Tambah\n";
        cout << "3. Cari Rute (Linear)\n";
        cout << "4. Cari Nomor (Jump)\n";
        cout << "5. Sort Nama (Merge)\n";
        cout << "6. Sort Harga (Selection)\n";
        cout << "0. Keluar\n";

        pilih = inputAngka("Pilih : ");

        if (pilih == 1) tampilkan(data, n);

        else if (pilih == 2) tambahKereta(data, n);

        else if (pilih == 3) {
            string asal = inputString("Asal : ");
            string tujuan = inputString("Tujuan : ");
            linearSearch(data, n, asal, tujuan);
        }

        else if (pilih == 4) {
            int no = inputAngka("Nomor kereta: ");
            int idx = jumpSearch(data, n, no);

            if (idx != -1)
                cout << "\nDitemukan: " << (data + idx)->nama << endl;
            else
                cout << "\nTidak ditemukan\n";
        }

        else if (pilih == 5) {
            mergeSort(data, 0, n - 1);
            cout << "Berhasil diurutkan (Nama)\n";
        }

        else if (pilih == 6) {
            selectionSort(data, n);
            cout << "Berhasil diurutkan (Harga)\n";
        }

        else if (pilih != 0) {
            cout << "Menu tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}