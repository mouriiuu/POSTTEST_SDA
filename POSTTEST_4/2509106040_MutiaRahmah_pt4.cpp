#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

#define MAX 100

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Penumpang {
    string nama;
    string namaKereta;
    string rute;
};

struct NodeAntrian {
    Penumpang data;
    NodeAntrian* next;
};

struct NodeRiwayat {
    Penumpang data;
    NodeRiwayat* next;
};

NodeAntrian* frontAntrian = nullptr;
NodeAntrian* rearAntrian  = nullptr;

bool isQueueEmpty() {
    return frontAntrian == nullptr;
}

void enqueue(Penumpang* p) {
    NodeAntrian* nodeBaru = new NodeAntrian;
    nodeBaru->data = *p;
    nodeBaru->next = nullptr;

    if (rearAntrian == nullptr) {
        frontAntrian = rearAntrian = nodeBaru;
    } else {
        rearAntrian->next = nodeBaru;
        rearAntrian = nodeBaru;
    }
    cout << p->nama << " berhasil masuk antrian.\n";
}

void pushRiwayat(Penumpang* p);

void dequeue() {
    if (isQueueEmpty()) {
        cout << "Queue underflow! Antrian kosong.\n";
        return;
    }
    NodeAntrian* temp = frontAntrian;
    cout << "\n=== TIKET DIPROSES ===\n";
    cout << "Nama   : " << temp->data.nama << "\n";
    cout << "Kereta : " << temp->data.namaKereta << "\n";
    cout << "Rute   : " << temp->data.rute << "\n";
    pushRiwayat(&temp->data);
    frontAntrian = frontAntrian->next;
    if (frontAntrian == nullptr) rearAntrian = nullptr;
    delete temp;
}

void peekAntrian() {
    if (isQueueEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "\n=== PENUMPANG TERDEPAN (PEEK QUEUE) ===\n";
    cout << "Nama   : " << frontAntrian->data.nama << "\n";
    cout << "Kereta : " << frontAntrian->data.namaKereta << "\n";
    cout << "Rute   : " << frontAntrian->data.rute << "\n";
}

void tampilAntrian() {
    if (isQueueEmpty()) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "\n=== ANTRIAN PEMBELIAN TIKET (QUEUE) ===\n";
    NodeAntrian* temp = frontAntrian;
    int i = 1;
    while (temp != nullptr) {
        cout << "[" << i << "] " << temp->data.nama << " | "
             << temp->data.namaKereta << " | " << temp->data.rute << "\n";
        temp = temp->next;
        i++;
    }
}

NodeRiwayat* topRiwayat = nullptr;

bool isStackEmpty() {
    return topRiwayat == nullptr;
}

void pushRiwayat(Penumpang* p) {
    NodeRiwayat* nodeBaru = new NodeRiwayat;
    nodeBaru->data = *p;
    nodeBaru->next = topRiwayat;
    topRiwayat = nodeBaru;
    cout << "Transaksi atas nama " << p->nama << " dicatat ke riwayat.\n";
}

void popRiwayat() {
    if (isStackEmpty()) {
        cout << "Stack underflow! Riwayat kosong.\n";
        return;
    }
    NodeRiwayat* temp = topRiwayat;
    cout << "Transaksi dibatalkan: " << temp->data.nama << " | "
         << temp->data.namaKereta << " | " << temp->data.rute << "\n";
    topRiwayat = topRiwayat->next;
    delete temp;
}

void peekRiwayat() {
    if (isStackEmpty()) {
        cout << "Riwayat kosong.\n";
        return;
    }
    cout << "\n=== TRANSAKSI TERAKHIR (PEEK STACK) ===\n";
    cout << "Nama   : " << topRiwayat->data.nama << "\n";
    cout << "Kereta : " << topRiwayat->data.namaKereta << "\n";
    cout << "Rute   : " << topRiwayat->data.rute << "\n";
}

void tampilRiwayat() {
    if (isStackEmpty()) {
        cout << "Riwayat kosong.\n";
        return;
    }
    cout << "\n=== RIWAYAT TRANSAKSI (STACK) ===\n";
    NodeRiwayat* temp = topRiwayat;
    int i = 1;
    while (temp != nullptr) {
        cout << "[" << i << "] " << temp->data.nama << " | "
             << temp->data.namaKereta << " | " << temp->data.rute << "\n";
        temp = temp->next;
        i++;
    }
}

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
    (arr + n)->nomor  = inputAngka("Nomor: ");
    (arr + n)->nama   = inputString("Nama: ");
    (arr + n)->asal   = inputString("Asal: ");
    (arr + n)->tujuan = inputString("Tujuan: ");
    (arr + n)->harga  = inputAngka("Harga: ");
    n++;
    cout << "Data berhasil ditambahkan!\n";
}

void linearSearch(Kereta* arr, int n, string asal, string tujuan) {
    if (n == 0) { cout << "Data kosong\n"; return; }
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
    if (!ketemu) cout << "Data tidak ditemukan.\n";
}

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
        if (prev >= n) return -1;
    }
    cout << "\nLinear Search dalam blok :\n";
    for (int i = prev; i < step && i < n; i++) {
        cout << "Cek index " << i
             << " (nomor : " << (arr + i)->nomor << ")\n";
        if ((arr + i)->nomor == target) return i;
    }
    return -1;
}

void merge(Kereta* arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];
    for (int i = 0; i < n1; i++) *(L + i) = *(arr + l + i);
    for (int j = 0; j < n2; j++) *(R + j) = *(arr + m + 1 + j);
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if ((L + i)->nama < (R + j)->nama) { *(arr + k) = *(L + i); i++; }
        else                                { *(arr + k) = *(R + j); j++; }
        k++;
    }
    while (i < n1) { *(arr + k) = *(L + i); i++; k++; }
    while (j < n2) { *(arr + k) = *(R + j); j++; k++; }
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
            if ((arr + j)->harga < (arr + min)->harga) min = j;
        }
        swapKereta((arr + i), (arr + min));
    }
}

void tambahAntrian(Kereta* arr, int n) {
    if (n == 0) { cout << "Tidak ada data kereta.\n"; return; }
    tampilkan(arr, n);
    int no = inputAngka("Masukkan nomor kereta yang ingin dipesan: ");
    Kereta* pilihan = nullptr;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->nomor == no) { pilihan = (arr + i); break; }
    }
    if (pilihan == nullptr) { cout << "Nomor kereta tidak ditemukan!\n"; return; }
    Penumpang p;
    p.nama       = inputString("Nama penumpang: ");
    p.namaKereta = pilihan->nama;
    p.rute       = pilihan->asal + " -> " + pilihan->tujuan;
    enqueue(&p);
}

int main() {
    Kereta data[100] = {
        {101, "Argo Bromo", "Jakarta",    "Surabaya",   500000},
        {102, "Taksaka",    "Jakarta",    "Yogyakarta", 400000},
        {103, "Malioboro",  "Yogyakarta", "Malang",     300000}
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
        cout << "7. Pesan Tiket (Enqueue)\n";
        cout << "8. Proses Tiket (Dequeue)\n";
        cout << "9. Lihat Antrian Terdepan (Peek Queue)\n";
        cout << "10. Tampil Semua Antrian\n";
        cout << "11. Batalkan Transaksi Terakhir (Pop)\n";
        cout << "12. Lihat Transaksi Terakhir (Peek Stack)\n";
        cout << "13. Tampil Semua Riwayat\n";
        cout << "0. Keluar\n";

        pilih = inputAngka("Pilih : ");

        if      (pilih == 1)  tampilkan(data, n);
        else if (pilih == 2)  tambahKereta(data, n);
        else if (pilih == 3) {
            string asal   = inputString("Asal : ");
            string tujuan = inputString("Tujuan : ");
            linearSearch(data, n, asal, tujuan);
        }
        else if (pilih == 4) {
            int no  = inputAngka("Nomor kereta: ");
            int idx = jumpSearch(data, n, no);
            if (idx != -1) cout << "\nDitemukan: " << (data + idx)->nama << endl;
            else           cout << "\nTidak ditemukan\n";
        }
        else if (pilih == 5)  { mergeSort(data, 0, n - 1); cout << "Berhasil diurutkan (Nama)\n"; }
        else if (pilih == 6)  { selectionSort(data, n);    cout << "Berhasil diurutkan (Harga)\n"; }
        else if (pilih == 7)  tambahAntrian(data, n);
        else if (pilih == 8)  dequeue();
        else if (pilih == 9)  peekAntrian();
        else if (pilih == 10) tampilAntrian();
        else if (pilih == 11) popRiwayat();
        else if (pilih == 12) peekRiwayat();
        else if (pilih == 13) tampilRiwayat();
        else if (pilih != 0)  cout << "Menu tidak valid!\n";

    } while (pilih != 0);
    
    return 0;
}