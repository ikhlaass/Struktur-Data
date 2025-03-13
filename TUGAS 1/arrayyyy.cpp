#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string kelas;
    string stanbuk;
    string alamat;
    int umur;
    char jenis_kelamin;
    string asal_daerah;
    string tempat_tinggal;
    string nama_ayah;
    string nama_ibu;
};

void tampilkanData(Mahasiswa mhs) {
    cout << "Nama Mahasiswa: " << mhs.nama << endl;
    cout << "Kelas: " << mhs.kelas << endl;
    cout << "Stanbuk: " << mhs.stanbuk << endl;
    cout << "Alamat Mahasiswa: " << mhs.alamat << endl;
    cout << "Umur: " << mhs.umur << endl;
    cout << "Jenis Kelamin: " << mhs.jenis_kelamin << endl;
    cout << "Asal Daerah: " << mhs.asal_daerah << endl;
    cout << "Tempat Tinggal: " << mhs.tempat_tinggal << endl;
    cout << "Nama Ayah: " << mhs.nama_ayah << endl;
    cout << "Nama Ibu: " << mhs.nama_ibu << endl;
    cout << endl;
}

int main() {
    system("clear"); 

    int jumlahMahasiswa;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;
    cout << endl;
    cin.ignore();


    Mahasiswa mahasiswa[jumlahMahasiswa]; 

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Masukkan data mahasiswa ke-" << (i + 1) << ":" << endl;

        cout << "Nama: ";
        getline(cin, mahasiswa[i].nama);
        cout << "Kelas: ";
        getline(cin, mahasiswa[i].kelas);
        cout << "Stanbuk: ";
        getline(cin, mahasiswa[i].stanbuk);
        cout << "Alamat: ";
        getline(cin, mahasiswa[i].alamat);
        cout << "Umur: ";
        cin >> mahasiswa[i].umur;
        cout << "Jenis Kelamin (P/L): ";
        cin >> mahasiswa[i].jenis_kelamin;
        cin.ignore(); 
        cout << "Asal Daerah: ";
        getline(cin, mahasiswa[i].asal_daerah);
        cout << "Tempat Tinggal: ";
        getline(cin, mahasiswa[i].tempat_tinggal);
        cout << "Nama Ayah: ";
        getline(cin, mahasiswa[i].nama_ayah);
        cout << "Nama Ibu: ";
        getline(cin, mahasiswa[i].nama_ibu);
        
        cout << endl;
    }

    cout << "------ DAFTAR DATA MAHASISWA ------" << endl << endl;

    for (int i = 0; i < jumlahMahasiswa; ++i) {
        tampilkanData(mahasiswa[i]);
    }

    return 0;
}
