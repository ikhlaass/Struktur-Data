#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

const int MAX_SLOT = 10; 
const int MAX_QUEUE = 10; 
const int MAX_RIWAYAT = MAX_SLOT * 2;

string slotParkir[MAX_SLOT];
string waktuParkir[MAX_SLOT];

string riwayatParkir[MAX_RIWAYAT];
string waktuMasukRiwayat[MAX_RIWAYAT];
string waktuKeluarRiwayat[MAX_RIWAYAT];
int jumlahRiwayat = 0;

string antreanMobil[MAX_QUEUE];
string waktuAntrean[MAX_QUEUE];
int frontAntrean = 0, rearAntrean = -1, jumlahAntrean = 0;

double pendapatan = 0;

string getWaktuSekarang() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);

    return string(buffer);
}

void garisHorizontal(int panjang) {
    for (int i = 0; i < panjang; i++) {
        cout << "-";
    }
    cout << endl;
}

void tampilkanMenu() {
    garisHorizontal(41);
    cout << "|          Aplikasi Parkir Mobil         |\n";
    garisHorizontal(41);
    cout << "| 1. Masukkan Mobil                      |\n";
    cout << "| 2. Keluarkan Mobil                     |\n";
    cout << "| 3. Lihat Slot Parkir                   |\n";
    cout << "| 4. Lihat Riwayat Parkir                |\n";
    cout << "| 5. Lihat Antrean                       |\n";
    cout << "| 6. Laporan Pendapatan                  |\n";
    cout << "| 0. Keluar                              |\n";
    garisHorizontal(41);
    cout << "Pilihan: ";
}

bool slotKosong(int slot) {
    return slotParkir[slot].empty();
}

void simpanSlotParkir() {
    ofstream file("slotParkir.txt");
    if (file.is_open()) {
        for (int i = 0; i < MAX_SLOT; i++) {
            file << slotParkir[i] << "," << waktuParkir[i] << endl;
        }
        file.close();
    }
}

void simpanRiwayatParkir() {
    ofstream file("riwayatParkir.txt");
    if (file.is_open()) {
        for (int i = 0; i < jumlahRiwayat; i++) {
            file << riwayatParkir[i] << "," << waktuMasukRiwayat[i] << "," << waktuKeluarRiwayat[i] << endl;
        }
        file.close();
    }
}

void simpanAntrean() {
    ofstream file("antreanMobil.txt");
    if (file.is_open()) {
        for (int i = frontAntrean; i <= rearAntrean; i++) {
            file << antreanMobil[i] << "," << waktuAntrean[i] << endl;
        }
        file.close();
    }
}

void bacaSlotParkir() {
    ifstream file("slotParkir.txt");
    if (file.is_open()) {
        string platNomor, waktu;
        int i = 0;
        while (getline(file, platNomor, ',') && getline(file, waktu)) {
            slotParkir[i] = platNomor;
            waktuParkir[i] = waktu;
            i++;
        }
        file.close();
    }
}

void bacaRiwayatParkir() {
    ifstream file("riwayatParkir.txt");
    if (file.is_open()) {
        string platNomor, waktuMasuk, waktuKeluar;
        while (getline(file, platNomor, ',') && getline(file, waktuMasuk, ',') && getline(file, waktuKeluar)) {
            riwayatParkir[jumlahRiwayat] = platNomor;
            waktuMasukRiwayat[jumlahRiwayat] = waktuMasuk;
            waktuKeluarRiwayat[jumlahRiwayat] = waktuKeluar;
            jumlahRiwayat++;
        }
        file.close();
    }
}

void bacaAntrean() {
    ifstream file("antreanMobil.txt");
    if (file.is_open()) {
        string platNomor, waktu;
        while (getline(file, platNomor, ',') && getline(file, waktu)) {
            antreanMobil[rearAntrean + 1] = platNomor;
            waktuAntrean[rearAntrean + 1] = waktu;
            rearAntrean++;
            jumlahAntrean++;
        }
        file.close();
    }
}

void masukkanMobil() {
    string platNomor;
    garisHorizontal(41);
    cout << "|           MENAMBAHKAN MOBIL           |\n";
    garisHorizontal(41);
    
    cout << "Masukkan plat nomor mobil: ";
    getline(cin, platNomor);

    cout << "Pilih slot parkir (1-" << MAX_SLOT << "): ";
    int slot;
    cin >> slot;
    cin.ignore(); 

    if (slot < 1 || slot > MAX_SLOT) {
        cout << "Slot tidak valid. Silakan coba lagi.\n";
        return;
    }

    slot--; 

    if (slotKosong(slot)) {
        slotParkir[slot] = platNomor;
        waktuParkir[slot] = getWaktuSekarang();

        cout << "\n\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "+ Mobil Plat    : " << platNomor << "\n"; 
        cout << "+ Slot          : " << slot + 1 << "\n";                                                                 
        cout << "+ Harga         : " << "5.000" << "\n";                                                                 
        cout << "+ Date          : " << getWaktuSekarang() << "\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";

    } else {
        if (jumlahAntrean < MAX_QUEUE) {
            rearAntrean++;
            antreanMobil[rearAntrean] = platNomor;
            waktuAntrean[rearAntrean] = getWaktuSekarang();
            jumlahAntrean++;

            cout << "\n\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "\nParkir penuh. Mobil Masuk Ke Daftar Antrian.\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
            cout << "+ Date          : " << waktuAntrean[rearAntrean] << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";

        } else {
            cout << "Parkir dan antrean penuh. Tidak dapat menerima mobil lagi.\n";
        }
    }
}

void keluarkanMobil() {
    string platNomor;
    garisHorizontal(41);
    cout << "|           MENGELUARKAN MOBIL           |\n";
    garisHorizontal(41);

    cout << "Masukkan plat nomor mobil yang akan dikeluarkan: ";
    getline(cin, platNomor);

    bool ditemukan = false;
    for (int i = 0; i < MAX_SLOT; i++) {
        if (slotParkir[i] == platNomor) {
            ditemukan = true;

            riwayatParkir[jumlahRiwayat] = slotParkir[i];
            waktuMasukRiwayat[jumlahRiwayat] = waktuParkir[i];
            waktuKeluarRiwayat[jumlahRiwayat] = getWaktuSekarang();
            jumlahRiwayat++;

            slotParkir[i].clear();
            waktuParkir[i].clear();

            pendapatan += 5000;

            cout << "\n\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "\nData Mobil Yang Keluar .\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "+ Mobil Plat    : " << platNomor << "\n";                                                                  
            cout << "+ Date          : " << getWaktuSekarang() << "\n";
            cout << "++++++++++++++++++++++++++++++++++++++++++\n\n";
            simpanRiwayatParkir();

            if (jumlahAntrean > 0) {
                slotParkir[i] = antreanMobil[frontAntrean];
                waktuParkir[i] = waktuAntrean[frontAntrean];

                for (int j = frontAntrean; j < rearAntrean; j++) {
                    antreanMobil[j] = antreanMobil[j + 1];
                    waktuAntrean[j] = waktuAntrean[j + 1];
                }
                rearAntrean--;
                jumlahAntrean--;

                cout << "Mobil dengan plat " << slotParkir[i] << " dipindahkan dari antrean ke slot.\n";
                simpanAntrean();  
                simpanSlotParkir(); 
            }

            break;
        }
    }

    if (!ditemukan) {
        cout << "Mobil dengan plat " << platNomor << " tidak ditemukan di slot parkir.\n";
    }
}

void lihatSlotParkir() {
    garisHorizontal(41);
    cout << "|           SLOT PARKIR SAAT INI         |\n";
    garisHorizontal(41);

    for (int i = 0; i < MAX_SLOT; i++) {
        cout << "Slot " << i + 1 << ": ";
        if (slotKosong(i)) {
            cout << "Kosong\n";
        } else {
            cout << slotParkir[i] << " (Masuk: " << waktuParkir[i] << ")\n";
        }
    }
}

void lihatRiwayatParkir() {
    garisHorizontal(41);
    cout << "|              RIWAYAT PARKIR             |\n";
    garisHorizontal(41);

    if (jumlahRiwayat == 0) {
        cout << "Belum ada riwayat parkir.\n";
    } else {
        for (int i = 0; i < jumlahRiwayat; i++) {
            cout << "Riwayat Ke-" << i + 1 << ": " << riwayatParkir[i] << "\n";
            cout << "  Masuk: " << waktuMasukRiwayat[i] << "\n";
            cout << "  Keluar: " << waktuKeluarRiwayat[i] << "\n";
            garisHorizontal(41);
        }
    }
}

void lihatAntrean() {
    garisHorizontal(41);
    cout << "|              ANTREAN SAAT INI            |\n";
    garisHorizontal(41);
    if (jumlahAntrean == 0) {
        cout << "Antrean kosong.\n";
    } else {
        for (int i = frontAntrean; i <= rearAntrean; i++) {
            cout << "Antrean Ke-" << i - frontAntrean + 1 << ": " << antreanMobil[i] << " (Masuk: " << waktuAntrean[i] << ")\n";
        }
    }
}

void laporanPendapatan() {
    garisHorizontal(41);
    cout << "|              LAPORAN PENDAPATAN          |\n";
    garisHorizontal(41);
    cout << "Total Pendapatan: Rp " << pendapatan << "\n";
}

int main() {
    bacaSlotParkir();
    bacaRiwayatParkir();
    bacaAntrean();

    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                masukkanMobil();
                break;
            case 2:
                keluarkanMobil();
                break;
            case 3:
                lihatSlotParkir();
                break;
            case 4:
                lihatRiwayatParkir();
                break;
            case 5:
                lihatAntrean();
                break;
            case 6:
                laporanPendapatan();
                break;
            case 0:
                cout << "Keluar dari aplikasi.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 0);

    return 0;
}
