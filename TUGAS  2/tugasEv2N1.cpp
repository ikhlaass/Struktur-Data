#include <iostream>  // Mengimpor pustaka iostream untuk input dan output
using namespace std; // Menggunakan ruang nama standar

#define MAKS 1000   // Mendefinisikan makro MAKS dengan nilai 1000 sebagai ukuran maksimum antrian

// Struktur data untuk antrian
struct Queue {
    int data[MAKS];  // Array untuk menyimpan elemen antrian
    int front, rear; // Indeks untuk elemen terdepan dan terakhir
};

// Fungsi untuk menginisialisasi antrian
void inisialisasiQueue(Queue &q) {
    q.front = -1;  // Mengatur indeks depan antrian ke -1 (menunjukkan antrian kosong)
    q.rear = -1;   // Mengatur indeks belakang antrian ke -1 (menunjukkan antrian kosong)
}

// Fungsi untuk memeriksa apakah antrian kosong
bool kosong(Queue &q) {
    return q.front == -1; // Mengembalikan true jika antrian kosong
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueue(Queue &q, int nilai) {
    if (q.rear == MAKS - 1) { // Memeriksa apakah antrian penuh
        cout << "Antrian penuh!" << endl; // Menampilkan pesan bahwa antrian penuh
    } else {
        if (q.front == -1) q.front = 0; // Jika antrian kosong, set front ke 0
        q.rear++; // Menaikkan indeks rear
        q.data[q.rear] = nilai; // Menambahkan nilai ke posisi rear
    }
}

// Fungsi untuk menghapus elemen dari antrian
int dequeue(Queue &q) {
    if (kosong(q)) { // Memeriksa apakah antrian kosong
        cout << "Antrian kosong!" << endl; // Menampilkan pesan bahwa antrian kosong
        return -1; // Mengembalikan -1 sebagai indikator antrian kosong
    } else {
        int nilai = q.data[q.front]; // Mengambil nilai dari posisi front
        // Memeriksa apakah antrian hanya memiliki satu elemen
        if (q.front >= q.rear) {
            q.front = -1; // Set front ke -1 (antrian kosong)
            q.rear = -1;  // Set rear ke -1 (antrian kosong)
        } else {
            q.front++; // Menaikkan indeks front
        }
        return nilai; // Mengembalikan nilai yang dihapus
    }
}

// Fungsi untuk mencetak segitiga bintang
void cetakSegitiga(int tinggi) {
    Queue q; // Membuat objek antrian
    inisialisasiQueue(q); // Menginisialisasi antrian
    for (int i = 1; i <= tinggi; i++) { // Loop untuk setiap baris segitiga
        enqueue(q, i); // Menambahkan tinggi baris ke antrian
        for (int j = 1; j <= q.data[q.rear]; j++) { // Loop untuk mencetak bintang
            cout << "* "; // Mencetak bintang
        }
        cout << endl; // Pindah ke baris berikutnya
    }
}

// Fungsi untuk mencetak kotak bintang
void cetakKotak(int sisi) {
    Queue q; // Membuat objek antrian
    inisialisasiQueue(q); // Menginisialisasi antrian
    for (int i = 0; i < sisi; i++) { // Loop untuk setiap baris kotak
        enqueue(q, sisi); // Menambahkan sisi kotak ke antrian
        for (int j = 0; j < q.data[q.rear]; j++) { // Loop untuk mencetak bintang
            cout << "* "; // Mencetak bintang
        }
        cout << endl; // Pindah ke baris berikutnya
    }
}

// Fungsi untuk mencetak persegi panjang bintang
void cetakPersegiPanjang(int panjang, int lebar) {
    Queue q; // Membuat objek antrian
    inisialisasiQueue(q); // Menginisialisasi antrian
    for (int i = 0; i < lebar; i++) { // Loop untuk setiap baris persegi panjang
        enqueue(q, panjang); // Menambahkan panjang persegi panjang ke antrian
        for (int j = 0; j < q.data[q.rear]; j++) { // Loop untuk mencetak bintang
            cout << "* "; // Mencetak bintang
        }
        cout << endl; // Pindah ke baris berikutnya
    }
}

// Fungsi untuk mencetak lingkaran bintang
void cetakLingkaran(int radius) {
    Queue q; // Membuat objek antrian
    inisialisasiQueue(q); // Menginisialisasi antrian

    // Loop untuk menentukan titik-titik pada lingkaran
    for (int i = 0; i <= 2 * radius; ++i) {
        for (int j = 0; j <= 2 * radius; ++j) {
            // Menghitung jarak dari titik pusat
            float jarak = sqrt((i - radius) * (i - radius) + (j - radius) * (j - radius));
            // Enqueue 1 jika berada pada tepi lingkaran, 0 jika tidak
            enqueue(q, (jarak > radius - 0.5 && jarak < radius + 0.5) ? 1 : 0);
        }
    }

    // Loop untuk mencetak lingkaran
    for (int i = 0; i <= 2 * radius; ++i) {
        for (int j = 0; j <= 2 * radius; ++j) {
            int isBintang = dequeue(q); // Mengambil nilai dari antrian
            cout << (isBintang ? "* " : "  "); // Mencetak bintang atau spasi
        }
        cout << endl; // Pindah ke baris berikutnya
    }
}

// Fungsi utama program
int main() {
    system("clear"); // Menghapus layar (hanya berfungsi di terminal Unix/Linux)

    int pilihan, dimensi1, dimensi2; // Mendeklarasikan variabel untuk pilihan dan dimensi

    // Loop untuk menu program
    while (true) {
        cout << "NAMA    : Andi Ikhlas Mallomo" << endl; // Menampilkan nama
        cout << "Stambuk : 13020230251" << endl; // Menampilkan stambuk
        cout << "\nMenu Bentuk Geometri:\n"; // Menampilkan menu
        cout << "1. Cetak Segitiga\n"; // Pilihan 1
        cout << "2. Cetak Kotak\n"; // Pilihan 2
        cout << "3. Cetak Persegi Panjang\n"; // Pilihan 3
        cout << "4. Cetak Lingkaran\n"; // Pilihan 4
        cout << "5. Keluar\n"; // Pilihan 5
        cout << "Masukkan pilihan: "; // Meminta input pilihan
        cin >> pilihan; // Menerima input dari pengguna

        if (pilihan == 5) { // Jika pilihan adalah 5, keluar dari program
            cout << "Keluar dari program.\n"; // Menampilkan pesan keluar
            break; // Keluar dari loop
        }

        // Menggunakan switch untuk memilih bentuk yang akan dicetak
        switch (pilihan) {
            case 1: // Kasus untuk mencetak segitiga
                cout << "Masukkan tinggi segitiga: "; // Meminta tinggi segitiga
                cin >> dimensi1; // Menerima input tinggi
                cetakSegitiga(dimensi1); // Memanggil fungsi cetakSegitiga
                break;
            case 2: // Kasus untuk mencetak kotak
                cout << "Masukkan sisi kotak: "; // Meminta sisi kotak
                cin >> dimensi1; // Menerima input sisi
                cetakKotak(dimensi1); // Memanggil fungsi cetakKotak
                break;
            case 3: // Kasus untuk mencetak persegi panjang
                cout << "Masukkan panjang persegi panjang: "; // Meminta panjang
                cin >> dimensi1; // Menerima input panjang
                cout << "Masukkan lebar persegi panjang: "; // Meminta lebar
                cin >> dimensi2; // Menerima input lebar
                cetakPersegiPanjang(dimensi1, dimensi2); // Memanggil fungsi cetakPersegiPanjang
                break;
            case 4: // Kasus untuk mencetak lingkaran
                cout << "Masukkan radius lingkaran: "; // Meminta radius lingkaran
                cin >> dimensi1; // Menerima input radius
                cetakLingkaran(dimensi1); // Memanggil fungsi cetakLingkaran
                break;
            default: // Jika pilihan tidak valid
                cout << "Pilihan tidak valid!\n"; // Menampilkan pesan pilihan tidak valid
                break;
        }
    }

    return 0; // Mengembalikan 0 menandakan program berakhir dengan sukses
}
