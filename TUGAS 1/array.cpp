#include <iostream>
using namespace std;

struct course {
    string matkul;
    float n_absensi, n_tugas, n_uts, n_uas, n_akhir;
};

struct student {
    string nama, kls, nim;
    int jumlah;
};

int main() {
    system("clear"); 
    student mhs;

    cout << "Masukkan Nama Anda: ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM Anda: ";
    cin >> mhs.nim;
    cout << "Masukkan Kelas Anda: ";
    cin >> mhs.kls;   

    cout << endl;

    cout << "Masukkan Jumlah Matakuliah: ";
    cin >> mhs.jumlah;

    cin.ignore(); 
    
    course matkul[mhs.jumlah];

    for (int i = 0; i < mhs.jumlah; i++) {
        cout << "Masukkan Nama Matakuliah ke " << i+1 << " :" ;
        getline(cin, matkul[i].matkul);

        cout << "Masukkan Nilai Absensi: ";
        cin >> matkul[i].n_absensi;
        cout << "Masukkan Nilai Tugas: ";
        cin >> matkul[i].n_tugas;
        cout << "Masukkan Nilai UTS: ";
        cin >> matkul[i].n_uts;
        cout << "Masukkan Nilai UAS: ";
        cin >> matkul[i].n_uas;

        // Hitung nilai akhir
        matkul[i].n_absensi *= 0.2;
        matkul[i].n_tugas *= 0.2;
        matkul[i].n_uts *= 0.3;
        matkul[i].n_uas *= 0.3;

        matkul[i].n_akhir = matkul[i].n_absensi + matkul[i].n_tugas + matkul[i].n_uts + matkul[i].n_uas;
        
        cin.ignore(); 
    }

    cout << endl << endl;
    cout << "NAMA   : " << mhs.nama << endl;
    cout << "NIM    : " << mhs.nim << endl;
    cout << "KELAS  : " << mhs.kls << endl << endl;

    cout << "Hasil Perhitungan Nilai:" << endl;
    cout << "===================================" << endl;

    for (int i = 0; i < mhs.jumlah; i++) {
        cout << "Matakuliah : " << matkul[i].matkul << endl;
        cout << "Nilai Akhir : " << matkul[i].n_akhir << endl;
        cout << "Index : ";
        if (matkul[i].n_akhir > 86) {
            cout << "A" << endl;
        } else if (matkul[i].n_akhir > 81) {
            cout << "A-" << endl;
        } else if (matkul[i].n_akhir > 76) {
            cout << "B+" << endl;
        } else if (matkul[i].n_akhir > 71) {
            cout << "B" << endl;
        } else if (matkul[i].n_akhir > 66) {
            cout << "B-" << endl;
        } else if (matkul[i].n_akhir > 61) {
            cout << "C+" << endl;
        } else if (matkul[i].n_akhir > 56) {
            cout << "C" << endl;
        } else {
            cout << "E" << endl;
        }

        cout << "===================================" << endl;
    }

    return 0;
}
