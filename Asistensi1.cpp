#include <iostream>
#include <string>
using namespace std;

const int KODE_PETUGAS = 159;
const int MAX = 100;
// Struktur untuk menyimpan informasi pembeli
struct DataPembeli {
    int stackPembeli[MAX];  // Ini tidak digunakan, bisa dihapus jika tidak diperlukan
    string nama;
    bool sudahDikonfirmasi; 
    int top = -1;           // Penunjuk elemen teratas dalam stack
} stackPembeli;

bool cekPetugas() {
    int kodeInput;
    cout << "Masukkan sandi: ";
    cin >> kodeInput;
    if (kodeInput == KODE_PETUGAS) {
        return true;
    } else {
        cout << "Kode akses salah!" << endl;
        return false;
    }
}

void push(string nama) {
    if (stackPembeli.top < 99) { 
        stackPembeli.top++; // Pindah ke posisi elemen teratas
        stackPembeli.nama = nama; // Menyimpan nama pembeli di stack
        stackPembeli.sudahDikonfirmasi = false; // Set konfirmasi menjadi false secara default
        cout << "Pembelian berhasil dicatat!" << endl;
    } else {
        cout << "Kuota tiket habis!" << endl;
    }
}

// Fungsi pop untuk menghapus pembeli dari stack
void pop() {
    if (stackPembeli.top == -1) { // Memeriksa apakah stack kosong
        cout << "Belum ada pembelian tiket yang bisa dibatalkan." << endl;
    } else {
        cout << "Tiket atas nama " << stackPembeli.nama << " berhasil dibatalkan." << endl;
        stackPembeli.top--; // Menghapus elemen teratas
    }
}

// Fungsi untuk memesan tiket
void pesanTiket() {
    cin.ignore(); 
    string nama;
    cout << "Masukkan nama pembeli: ";
    getline(cin, nama);
    push(nama); // Menambah pembeli ke stack
}

// Fungsi untuk menampilkan daftar pembeli yang sudah dikonfirmasi
void tampilkanDaftarPembelian() {
    if (stackPembeli.top == -1) {
        cout << "Belum ada pembeli tiket." << endl;
    } else {
        cout << "Daftar pembeli tiket yang sudah dikonfirmasi:" << endl;
        bool adaPembeliTerkonfirmasi = false; // Flag untuk mengecek apakah ada pembeli yang sudah dikonfirmasi
        for (int i = stackPembeli.top; i >= 0; i--) { // Menampilkan hanya yang sudah dikonfirmasi
            if (stackPembeli.sudahDikonfirmasi) {
                cout << "- " << stackPembeli.nama << endl;
                adaPembeliTerkonfirmasi = true;
            }
        }
        if (!adaPembeliTerkonfirmasi) {
            cout << "Belum ada pembeli yang dikonfirmasi." << endl;
        }
    }
}

// Fungsi untuk memverifikasi pembeli
void verifikasiPembeli() {
    string nama;
    cin.ignore();
    cout << "Masukkan nama: ";
    getline(cin, nama);
    
    for (int i = stackPembeli.top; i >= 0; i--) { // Cek dari teratas ke bawah
        if (stackPembeli.nama == nama) {
            stackPembeli.sudahDikonfirmasi = true; // Mengubah status menjadi dikonfirmasi
            cout << "Data atas nama " << nama << " telah dikonfirmasi!" << endl;
            return;
        }
    }
    cout << "Nama tidak ditemukan." << endl;
}

int main() {
    system("clear");
    int pilihan;

    while (true) {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Pembeli" << endl;
        cout << "2. Petugas" << endl;
        cout << "3. Keluar" << endl;
        cout << "Masuk sebagai: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int opsi;
            cout << "\n1. Pesan Tiket" << endl;
            cout << "2. Batalkan Tiket" << endl;
            cout << "Masukkan pilihan: ";
            cin >> opsi;

            if (opsi == 1) {
                pesanTiket();
            } else if (opsi == 2) {
                pop(); // Menghapus tiket teratas
            } else {
                cout << "Pilihan tidak valid." << endl;
            }
        } else if (pilihan == 2) {
            if (cekPetugas()) {
                int menuPetugas;
                while (true) {
                    cout << endl;
                    cout << "1. Konfirmasi pembelian tiket" << endl;
                    cout << "2. List pembelian tiket" << endl;
                    cout << "0. Kembali ke menu utama" << endl;
                    cout << "Masukkan pilihan: ";
                    cin >> menuPetugas;

                    if (menuPetugas == 1) {
                        verifikasiPembeli();
                    } else if (menuPetugas == 2) {
                        tampilkanDaftarPembelian();
                    } else if (menuPetugas == 0) {
                        break;
                    } else {
                        cout << "Pilihan tidak valid." << endl;
                    }
                }
            }
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
