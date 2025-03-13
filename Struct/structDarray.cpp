#include <iostream>
#include <string>
using namespace std;

struct Kehadiran {
    int izin;
    int sakit;
};

struct Data {
    string nama;
    double nim;
    Kehadiran hdr;
} dta[5];

int main() {
    int count = 0;
    char pil;

    do {
        if (count >= 5) {
            cout << "Data penuh, tidak bisa menambahkan lagi." << endl;
            break;
        }

        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, dta[count].nama);

        cout << "Masukkan NIM: ";
        cin >> dta[count].nim;

        cout << "Masukkan Jumlah izin: ";
        cin >> dta[count].hdr.izin;

        cout << "Masukkan Jumlah sakit: ";
        cin >> dta[count].hdr.sakit;

        count++;

        cout << "Apakah anda ingin menambahkan data lagi (y/t): ";
        cin >> pil;
    } while (pil == 'y' || pil == 'Y');

    cout << "\nData yang dimasukkan:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\nData ke-" << (i + 1) << ":" << endl;
        cout << "Nama   : " << dta[i].nama << endl;
        cout << "NIM    : " << dta[i].nim << endl;
        cout << "Izin   : " << dta[i].hdr.izin << endl;
        cout << "Sakit  : " << dta[i].hdr.sakit << endl;
    }

    return 0;
}
