#include <iostream> // Library untuk input dan output data
using namespace std; // Mempermudah penggunaan standar library

int main() {
    int baris, kolom; // Variabel untuk menyimpan jumlah baris dan kolom

    // Meminta jumlah baris dari pengguna
    cout << "Masukkan jumlah baris: ";
    cin >> baris;

    // Meminta jumlah kolom dari pengguna
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    // Alokasi memori dinamis untuk array 2D
    int** dataMatriks = new int*[baris];
    for (int x = 0; x < baris; x++) {
        dataMatriks[x] = new int[kolom]; // Alokasikan setiap baris
    }

    // Input nilai-nilai elemen matriks dari pengguna
    cout << "Masukkan elemen matriks:\n";
    for (int x = 0; x < baris; x++) { // Iterasi setiap baris
        for (int y = 0; y < kolom; y++) { // Iterasi setiap kolom
            cin >> dataMatriks[x][y]; // Masukkan nilai elemen
        }
    }

    // Tampilkan matriks yang telah diinput
    cout << "Matriks yang dimasukkan:\n";
    for (int x = 0; x < baris; x++) { // Iterasi baris
        for (int y = 0; y < kolom; y++) { // Iterasi kolom
            cout << dataMatriks[x][y] << " "; // Tampilkan elemen
        }
        cout << endl; // Baris baru setelah satu baris selesai
    }

    // Hapus alokasi memori dinamis
    for (int x = 0; x < baris; x++) {
        delete[] dataMatriks[x]; // Hapus setiap baris
    }
    delete[] dataMatriks; // Hapus array utama

    return 0; // Program selesai
}
