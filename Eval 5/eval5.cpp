#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

int main() {
    string namaFile;

    cout << "Masukkan nama file : ";
    getline(cin, namaFile);
    cin.ignore(); 

    ofstream fileTulis(namaFile);
    if (!fileTulis) {
        cout << "File tidak bisa dibuat!" << endl;
        return 1;
    }
    
    string nama, prodi;
    int umur;

    cout << "Masukkan data yang ingin ditulis ke file:" << endl;
    cout << "Masukkan Nama: ";
    getline(cin, nama); 
    cout << "Masukkan Umur: ";
    cin >> umur;
    cin.ignore(); 
    cout << "Masukkan Prodi: ";
    getline(cin, prodi); 

    fileTulis << "Nama : " << nama << endl;
    fileTulis << "Umur : " << umur << endl;
    fileTulis << "Prodi : " << prodi << endl;

    fileTulis.close(); 

    ifstream fileBaca(namaFile);
    if (!fileBaca) {
        cout << "File tidak ditemukan!" << endl;
        return 1;
    }

    cout << "\nIsi file " << namaFile << " adalah:" << endl;
    string baris;
    while (getline(fileBaca, baris)) { 
        cout << baris << endl;
    }

    fileBaca.close(); 
    return 0;
}
