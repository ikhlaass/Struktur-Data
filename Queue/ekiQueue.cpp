#include <iostream>
using namespace std;

#define MAX 8
#define MAX_BARANG 5  

struct Pembelian {
    string nama;
    string barang[MAX_BARANG];
    int jumlah[MAX_BARANG];
    int totalBarang;  
};

struct queue {
    Pembelian data[MAX];
    int head;
    int tail;
} antrian;

void Create() {
    antrian.head = antrian.tail = -1;
}

bool IsEmpty() {
    return antrian.tail == -1;
}

bool IsFull() {
    return antrian.tail == MAX - 1;
}

void Enqueue(string nama, string barang[], int jumlah[], int jumlahBarang) {
    if (IsFull()) {
        cout << "Queue Penuh! Tidak bisa menambahkan lebih banyak pembelian.\n";
        return;
    }

    if (IsEmpty()) {
        antrian.head = antrian.tail = 0;
    } else {
        antrian.tail++;
    }

    antrian.data[antrian.tail].nama = nama;
    antrian.data[antrian.tail].totalBarang = jumlahBarang;

    for (int i = 0; i < jumlahBarang; i++) {
        antrian.data[antrian.tail].barang[i] = barang[i];
        antrian.data[antrian.tail].jumlah[i] = jumlah[i];
    }

    cout << "\nPembelian oleh " << antrian.data[antrian.tail].nama << " berhasil dimasukkan ke dalam antrian\n\n";
}

void Dequeue() {
    if (!IsEmpty()) {
        cout << "Proses Pembelian\n";
        cout << "================\n\n";
        cout << "Proses pembelian oleh " << antrian.data[antrian.head].nama << " sedang diproses:\n";

        for (int i = 0; i < antrian.data[antrian.head].totalBarang; i++) {
            cout << "- " << antrian.data[antrian.head].barang[i] << " sebanyak " << antrian.data[antrian.head].jumlah[i] << endl;
        }

        for (int i = antrian.head; i < antrian.tail; i++) {
            antrian.data[i] = antrian.data[i + 1];
        }
        antrian.tail--;
        if (antrian.tail == -1) {
            antrian.head = -1;
        }
    } else {
        cout << "Queue Kosong! Tidak ada pembelian untuk diproses.\n";
    }
}

void tampilkan() {
    if (IsEmpty()) {
        cout << "Queue Kosong\n";
    } else {
        cout << "Isi Antrian\n";
        cout << "===========\n";
        for (int i = antrian.head; i <= antrian.tail; i++) {
            cout << "Nama: " << antrian.data[i].nama << endl;
            cout << "Barang yang dibeli:\n";
            for (int j = 0; j < antrian.data[i].totalBarang; j++) {
                cout << " - " << antrian.data[i].barang[j] << ", Jumlah: " << antrian.data[i].jumlah[j] << endl;
            }
            cout << endl;
        }
    }
}

void Clear() {
    cout << "Kosongkan Antrian\n";
    cout << "=================\n\n";
    antrian.head = antrian.tail = -1;
    cout << "Antrian Telah Di Kososngkan.\n";
}

void pause() {
    cout << "\nTekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void menu() {
    cout << "Nama: Rezki\n";
    cout << "NIM: 13020230139\n\n";
    cout << "ICLabs Shop - Antrian Pembelanjaan\n";
    cout << "=================================\n";
    cout << "Menu:\n";
    cout << "1. Tambah Pembelian (Enqueue)\n";
    cout << "2. Proses Pembelian (Dequeue)\n";
    cout << "3. Tampilkan Isi Antrian\n";
    cout << "4. Kosongkan Antrian\n";
    cout << "5. Keluar\n";
}

int main() {
    int pil;
    Create();

    do {
        system("clear");
        menu();
        cout << "Masukkan pilihan [1..5]: ";
        cin >> pil;

        switch (pil) {
            case 1: {
                system("clear");
                if (IsFull()) {
                    cout << "Queue Penuh!\n";
                } else {
                    string nama;
                    int jumlahBarang;

                    cout << "Tambah Pembelian\n";
                    cout << "================\n";
                    cin.ignore();

                    cout << "Masukkan Nama Pembeli: ";
                    getline(cin, nama);

                    cout << "Masukkan Jumlah Jenis Barang yang dibeli : ";
                    cin >> jumlahBarang;

                    string barang[MAX_BARANG];
                    int jumlah[MAX_BARANG];

                    for (int i = 0; i < jumlahBarang; i++) {
                        cin.ignore();
                        cout << "Masukkan Nama Barang Ke-" << i + 1 << ": ";
                        getline(cin, barang[i]);

                        cout << "Masukkan Jumlah Barang Ke-" << i + 1 << ": ";
                        cin >> jumlah[i];
                    }
                    Enqueue(nama, barang, jumlah, jumlahBarang);
                }
                pause();
                break;
            }
            case 2:
                system("clear");
                Dequeue(); 
                pause();
                break;
            case 3:
                system("clear");
                tampilkan();
                pause();
                break;
            case 4:
                system("clear");
                Clear();
                pause();
                break;
            case 5:
                system("clear");
                cout << "Program telah selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                pause();
                break;
        }
    } while (pil != 5);

    return 0;
}
