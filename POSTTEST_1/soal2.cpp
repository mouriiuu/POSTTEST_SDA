// input data 5 mahasiswa (nama, NIM, IPK).
// Cari dan tampilkan mahasiswa dengan IPK tertinggi

#include <iostream>
using namespace std;

struct data_Mahasiswa {
    string Nama;
    int NIM;
    float IPK;
};

int main() {
    data_Mahasiswa mhs[5];
    int ipk_tertinggi = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan Nama Mahasiswa : ";
        cin >> mhs[i].Nama;
        cout << "Masukkan NIM Mahasiswa : ";
        cin >> mhs[i].NIM;
        cout << "Masukkan IPK Mahasiswa : ";
        cin >> mhs[i].IPK;
        cout << endl;
    }
    
    for (int i = 1; i < 5; i++){
        if (mhs[i].IPK > mhs[ipk_tertinggi].IPK) {
            ipk_tertinggi = i;
        }
    }
    cout << "Mahasiswa Dengan IPK Tertinggi" << endl;
    cout << "Nama : " << mhs[ipk_tertinggi].Nama << endl;
    cout << "NIM : " << mhs[ipk_tertinggi].NIM << endl;
    cout << "IPK : " << mhs[ipk_tertinggi].IPK << endl;

    return 0;
}