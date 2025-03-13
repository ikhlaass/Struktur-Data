#include <iostream> // Mengimpor library untuk input dan output.
using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std::.

const int MAKS = 100;  // Batas maksimal jumlah elemen dalam antrian dan stack.

struct Antrian { // Mendefinisikan struktur Antrian.
    int depan, belakang; // Indeks untuk menunjukkan elemen depan dan belakang dari antrian.
    string pelanggan[MAKS]; // Array untuk menyimpan nama pelanggan.

    Antrian() { // inisialisasi objek Antrian.
        depan = -1; // Inisialisasi indeks depan ke -1 (antrian kosong).
        belakang = -1; // Inisialisasi indeks belakang ke -1 (antrian kosong).
    }

    bool penuh() { // Fungsi untuk memeriksa apakah antrian penuh.
        return belakang == MAKS - 1; // Mengembalikan true jika belakang mencapai indeks maksimal.
    }

    bool kosong() { // Fungsi untuk memeriksa apakah antrian kosong.
        return depan == -1 || depan > belakang; // Mengembalikan true jika antrian kosong.
    }

    void tambah(string pelangganBaru) { // Fungsi untuk menambahkan pelanggan baru ke antrian.
        if (penuh()) { // Memeriksa apakah antrian penuh.
            cout << "Antrian penuh, tidak dapat menambah pelanggan baru.\n"; // Pesan jika antrian penuh.
        } else {
            if (depan == -1) depan = 0; // Jika antrian kosong, set depan ke 0.
            pelanggan[++belakang] = pelangganBaru; // Tambah pelanggan ke belakang 
            cout << "Pelanggan " << pelangganBaru << " ditambahkan ke dalam antrian.\n"; 
        }
    }

    void hapus() { // Fungsi untuk menghapus pelanggan dari antrian.
        if (kosong()) { // Memeriksa apakah antrian kosong.
            cout << "Antrian kosong, tidak ada pelanggan untuk diselesaikan.\n"; // Pesan jika antrian kosong.
        } else {
            cout << "Pelanggan " << pelanggan[depan] << " telah menyelesaikan belanja.\n"; 
            depan++; // Pindahkan depan ke pelanggan berikutnya.
        }
    }

    void tampilkan() { // Fungsi untuk menampilkan semua pelanggan dalam antrian.
        if (kosong()) { // Memeriksa apakah antrian kosong.
            cout << "Antrian kosong.\n"; // Pesan jika antrian kosong.
        } else {
            cout << "Daftar antrian pelanggan:\n"; // Pesan utk menampilkan daftar pelanggan.
            for (int i = depan; i <= belakang; i++) { // Loop untuk menampilkan semua pelanggan.
                cout << i - depan + 1 << ". " << pelanggan[i] << endl; // Tampilkan pelanggan dengan nomor urut.
            }
        }
    }
};

struct Stack { // Mendefinisikan struktur Stack.
    int atas; // Indeks untuk elemen paling atas dari stack.
    string barang[MAKS]; // Array untuk menyimpan nama barang.
    string pelanggan[MAKS]; // Array untuk menyimpan nama pelanggan yang sesuai dengan barang.
    int jumlahBarang[MAKS]; // Array untuk menyimpan jumlah barang berdasarkan pelanggan.

    Stack() { // inisialisasi objek Stack.
        atas = -1; // Inisialisasi stack kosong.
        for (int i = 0; i < MAKS; i++) { // Loop untuk menginisialisasi jumlahBarang.
            jumlahBarang[i] = 0; //Inisialisasi jumlahBarang untuk setiap pelanggan.
        }
    }

    bool penuh() { // Fungsi untuk memeriksa apakah stack penuh.
        return atas == MAKS - 1; // Mengembalikan true jika atas mencapai indeks maksimal.
    }

    bool kosong() { // Fungsi untuk memeriksa apakah stack kosong.
        return atas == -1; // Mengembalikan true jika stack kosong.
    }

    void dorong(string item, string pelangganBaru) { // Fungsi untuk menambahkan barang ke stack.
        if (penuh()) { // Memeriksa apakah stack penuh.
            cout << "Keranjang belanja penuh, tidak dapat menambah barang.\n"; // Pesan jika keranjang penuh.
        } else {
            atas++; // Increment atas.
            barang[atas] = item; // Tambahkan barang ke stack.
            pelanggan[atas] = pelangganBaru; // Simpan nama pelanggan sesuai dengan barang.
            jumlahBarang[atas] = atas; // Simpan indeks barang.
            cout << "Barang " << item << " ditambahkan ke dalam keranjang belanja untuk " << pelangganBaru << ".\n"; // Pesan konfirmasi.
        }
    }

    void tampilkanBarangPertama(string pelangganBaru) { // Fungsi untuk menampilkan barang pertama untuk pelanggan tertentu.
        if (kosong()) { // Memeriksa apakah stack kosong.
            cout << "Keranjang belanja kosong untuk " << pelangganBaru << ".\n"; // Pesan jika keranjang kosong.
        } else {
            // Mencari barang pertama yang ditambahkan untuk pelanggan ini.
            for (int i = 0; i <= atas; i++) { // Loop untuk mencari barang untuk pelanggan.
                if (pelanggan[i] == pelangganBaru) { // Jika pelanggan cocok.
                    cout << "Barang di keranjang pelanggan " << pelangganBaru << ": " << barang[i] << endl; // Tampilkan barang pertama.
                    return; // Keluar dari fungsi setelah menemukan barang.
                }
            }
            cout << "Tidak ditemukan barang untuk pelanggan " << pelangganBaru << ".\n"; // Pesan jika tidak ditemukan barang.
        }
    }

    void kosongkan() { // Fungsi untuk mengosongkan stack.
        atas = -1; // Kosongkan stack dengan mengatur atas ke -1.
        cout << "Keranjang belanja telah dikosongkan.\n"; // Pesan konfirmasi.
    }
};

int main() { // Fungsi utama program.
    system("clear"); // Membersihkan layar terminal (hanya berfungsi di beberapa sistem).
    Antrian ikhlas; // Membuat objek ikhlas dari struktur Antrian.
    Stack ikhlass; // Membuat objek ikhlass dari struktur Stack.
    int pilihan; // Menyimpan pilihan menu dari pengguna.
    string nama, barang; // Variabel untuk menyimpan nama pelanggan dan barang.

    do {
        // Menampilkan informasi program dan menu.
        cout << "Nama : Andi Ikhlas Mallomo\n"; // Menampilkan nama pemilik program.
        cout << "Nim  : 13020230251\n"; // Menampilkan NIM pemilik program.
        cout << "\nUMI Mart\n"; // Judul program.
        cout << "1. Tambah pelanggan ke antrian\n"; // Opsi 1: Tambah pelanggan.
        cout << "2. Tambah barang ke keranjang pelanggan\n"; // Opsi 2: Tambah barang.
        cout << "3. Tampilkan antrian pelanggan\n"; // Opsi 3: Tampilkan antrian.
        cout << "4. Tampilkan barang di keranjang pelanggan\n"; // Opsi 4: Tampilkan barang.
        cout << "5. Selesaikan belanja dan hapus pelanggan dari antrian\n"; // Opsi 5: Selesaikan belanja.
        cout << "6. Keluar\n"; // Opsi 6: Keluar dari program.
        cout << "Pilih opsi: "; // Pesan untuk memilih opsi.
        cin >> pilihan; // Membaca input pilihan dari pengguna.
        cin.ignore(); // Mengabaikan karakter newline agar input berikutnya bisa menggunakan 'getline'.

        switch (pilihan) { // Memilih aksi berdasarkan pilihan pengguna.
            case 1: // Kasus untuk menambah pelanggan.
                system("clear"); // Membersihkan layar.
                cout << "Masukkan nama pelanggan: "; // Pesan untuk memasukkan nama pelanggan.
                getline(cin, nama); // Membaca nama pelanggan.
                ikhlas.tambah(nama); // Menambahkan pelanggan ke antrian.
                break;
            case 2: // Kasus untuk menambah barang ke keranjang.
                system("clear"); // Membersihkan layar.
                cout << "Masukkan nama barang: "; // Pesan untuk memasukkan nama barang.
                getline(cin, barang); // Membaca nama barang.
                ikhlass.dorong(barang, nama); // Menambahkan barang ke keranjang (stack) dengan nama pelanggan saat ini.
                break;
            case 3: // Kasus untuk menampilkan antrian pelanggan.
                system("clear"); // Membersihkan layar.
                ikhlas.tampilkan(); // Menampilkan semua pelanggan dalam antrian.
                break;
            case 4: // Kasus untuk menampilkan barang di keranjang pelanggan.
                system("clear"); // Membersihkan layar.
                if (!ikhlas.kosong()) { // Memeriksa apakah antrian tidak kosong.
                    ikhlass.tampilkanBarangPertama(ikhlas.pelanggan[ikhlas.depan]); // Menampilkan barang pertama dalam keranjang untuk pelanggan di depan antrian.
                } else {
                    cout << "Tidak ada pelanggan dalam antrian.\n"; // Jika antrian kosong.
                }
                break;
            case 5: // Kasus untuk menyelesaikan belanja pelanggan.
                system("clear"); // Membersihkan layar.
                if (!ikhlas.kosong()) { // Memeriksa apakah antrian tidak kosong.
                    ikhlas.hapus(); // Menghapus pelanggan pertama dari antrian.
                    // Mengosongkan keranjang setelah pelanggan selesai belanja.
                } else {
                    cout << "Antrian kosong, tidak ada pelanggan untuk diselesaikan.\n"; // Pesan jika antrian kosong.
                }
                break;
            case 6: // Kasus untuk keluar dari program.
                system("clear"); // Membersihkan layar.
                ikhlass.kosongkan(); // Mengosongkan keranjang sebelum keluar.
                cout << "Terima kasih telah menggunakan UMI Mart!\n"; // Pesan saat keluar dari program.
                break;
            default: // Kasus jika pilihan tidak valid.
                cout << "Pilihan tidak valid, coba lagi.\n"; // Pesan jika pilihan tidak sesuai.
        }
    } while (pilihan != 6); // Loop terus hingga pengguna memilih untuk keluar.

    return 0; // Mengakhiri program.
}