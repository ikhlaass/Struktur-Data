#include <iostream>
using namespace std;

// Struktur untuk node dari linked list
struct Node {
    int data;        // Data yang disimpan di node
    Node* next;     // Pointer ke node berikutnya
};

Node* head = nullptr;         // Pointer ke head linked list
int lastDeletedValue = -1;    // Variabel global untuk menyimpan nilai node terakhir yang dihapus

// Fungsi untuk membuat node baru di awal list
void buatNodeAwal(int nilai) {
    head = new Node();        // Alokasikan memori untuk node baru
    head->data = nilai;       // Simpan nilai di node
    head->next = nullptr;     // Node baru menjadi node terakhir
    cout << "Nilai " << nilai << " berhasil dimasukkan di node awal\n";
}

// Fungsi untuk menambahkan node di depan list
void tambahNodeDepan(int nilai) {
    Node* newNode = new Node(); // Alokasikan memori untuk node baru
    newNode->data = nilai;       // Simpan nilai di node
    newNode->next = head;        // Pointer ke node sebelumnya
    head = newNode;              // Update head ke node baru
    cout << "Nilai " << nilai << " berhasil ditambahkan di depan\n";
}

// Fungsi untuk menambahkan node di belakang list
void tambahNodeBelakang(int nilai) {
    Node* newNode = new Node(); // Alokasikan memori untuk node baru
    newNode->data = nilai;       // Simpan nilai di node
    newNode->next = nullptr;     // Node baru menjadi node terakhir

    if (head == nullptr) {        // Jika list kosong
        head = newNode;           // Head menjadi node baru
    } else {
        Node* temp = head;        // Temp pointer untuk traversing
        while (temp->next != nullptr) { // Cari node terakhir
            temp = temp->next;
        }
        temp->next = newNode;     // Tambahkan node baru di belakang
    }
    cout << "Nilai " << nilai << " berhasil ditambahkan di belakang\n";
}

// Fungsi untuk menambahkan node setelah node dengan nilai tertentu
void tambahNodeSetelah(int nilaiBaru, int nilaiTarget) {
    if (head == nullptr) { // Jika list kosong
        cout << "List kosong, tidak dapat menambahkan node setelah nilai yang ditentukan.\n";
    } else {
        Node* newNode = new Node(); // Alokasikan memori untuk node baru
        newNode->data = nilaiBaru;   // Simpan nilai baru

        Node* temp = head;            // Temp pointer untuk traversing
        while (temp != nullptr && temp->data != nilaiTarget) { // Cari nilai target
            temp = temp->next;
        }

        if (temp == nullptr) { // Jika nilai target tidak ditemukan
            cout << "Nilai " << nilaiTarget << " tidak ditemukan.\n";
        } else {
            newNode->next = temp->next; // Update pointer node baru
            temp->next = newNode;        // Tempatkan node baru setelah nilai target
            cout << "Nilai " << nilaiBaru << " berhasil ditambahkan setelah nilai " << nilaiTarget << ".\n";
        }
    }
}
// Fungsi untuk menghapus node di depan list
void hapusNodeDepan() {
    if (head == nullptr) { // Jika list kosong
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head; // Simpan node yang akan dihapus
    head = head->next; // Update head ke node berikutnya
    lastDeletedValue = temp->data; // Simpan nilai node yang dihapus
    cout << "Node pada posisi depan dengan nilai " << temp->data << " berhasil dihapus\n";
    delete temp; // Hapus node
}

// Fungsi untuk menghapus node di belakang list
void hapusNodeBelakang() {
    if (head == nullptr) { // Jika list kosong
        cout << "List kosong!\n";
        return;
    }

    if (head->next == nullptr) { // Jika hanya ada satu node
        lastDeletedValue = head->data; // Simpan nilai node yang dihapus
        cout << "Node pada posisi belakang dengan nilai " << head->data << " berhasil dihapus\n";
        delete head; // Hapus node
        head = nullptr; // Update head menjadi nullptr
    } else {
        Node* temp = head; // Temp pointer untuk traversing
        while (temp->next->next != nullptr) { // Cari node sebelum terakhir
            temp = temp->next;
        }
        lastDeletedValue = temp->next->data; // Simpan nilai node yang dihapus
        cout << "Node pada posisi belakang dengan nilai " << temp->next->data << " berhasil dihapus\n";
        delete temp->next; // Hapus node terakhir
        temp->next = nullptr; // Update pointer node sebelumnya
    }
}

// Fungsi untuk menghapus node dengan nilai tertentu
void hapusNodeTengah(int nilai) {
    if (head == nullptr) { // Jika list kosong
        cout << "List kosong!\n";
        return;
    }

    if (head->data == nilai) { // Jika node pertama yang dihapus
        hapusNodeDepan();
        return;
    }

    Node* temp = head; // Temp pointer untuk traversing
    while (temp->next != nullptr && temp->next->data != nilai) { // Cari node yang ingin dihapus
        temp = temp->next;
    }

    if (temp->next == nullptr) { // Jika nilai tidak ditemukan
        cout << "Node dengan nilai " << nilai << " tidak ditemukan!!\n";
    } else {
        Node* delNode = temp->next; // Simpan node yang akan dihapus
        temp->next = delNode->next; // Update pointer
        cout << "Node dengan nilai " << nilai << " berhasil dihapus\n";
        delete delNode; // Hapus node
    }
}

// Fungsi untuk menampilkan semua data dalam linked list
void tampilData() {
    if (head == nullptr) { // Jika list kosong
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head; // Temp pointer untuk traversing
    while (temp != nullptr) { // Tampilkan setiap node
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n"; // Tampilkan akhir list

    // Tampilkan nilai node terakhir yang dihapus jika ada
    if (lastDeletedValue != -1) {
        cout << "Node terakhir yang dihapus: " << lastDeletedValue << "\n";
        lastDeletedValue = -1; // Reset setelah ditampilkan
    }
}

// Menu untuk menambah node
void menuTambahNode() {
    int pilihan, nilai, nilaiTarget;
    if (head == nullptr) {
        cout << "Node Belum Tersedia\n"; // Jika tidak ada node
    } else {
        do {
            system("clear"); // Bersihkan layar
            cout << "Menu Tambah Node\n================\n";
            cout << "1. Tambah Node di Depan\n2. Tambah Node di Belakang\n3. Tambah Node Di Tengah\n4. Batal\n";
            cout << "Masukkan pilihan: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1: // Tambah node di depan
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    if (cin.fail()) { // Cek input
                        cin.clear(); // Bersihkan flag kesalahan
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Abaikan input yang tidak valid
                        cout << "Input is not valid.\n"; // Tampilkan pesan kesalahan
                    } else {
                        tambahNodeDepan(nilai); // Panggil fungsi
                    }
                    break;
                case 2: // Tambah node di belakang
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    if (cin.fail()) { // Cek input
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input is not valid.\n"; // Tampilkan pesan kesalahan
                    } else {
                        tambahNodeBelakang(nilai); // Panggil fungsi
                    }
                    break;
                case 3: // Tambah node setelah nilai tertentu
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    if (cin.fail()) { // Cek input
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input is not valid.\n"; // Tampilkan pesan kesalahan
                    } else {
                        tampilData(); // Tampilkan data sebelum menambah
                        cout << "Masukkan nilai setelah nilai: ";
                        cin >> nilaiTarget;
                        if (cin.fail()) { // Cek input
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Input is not valid.\n"; // Tampilkan pesan kesalahan
                        } else {
                            tambahNodeSetelah(nilai, nilaiTarget); // Panggil fungsi
                        }
                    }
                    break;
                case 4: // Batal
                    cout << "Batal.\n"; 
                    break; 
                default: // Pilihan tidak valid
                    cout << "Pilihan tidak valid!\n";
            }
            system("read -p 'Press Enter to continue...' var"); // Tunggu input
        } while (pilihan != 4); // Ulangi hingga batal
    }
}

// Menu untuk menghapus node
void menuHapusNode() {
    int pilihan, nilai;
    do {
        system("clear"); // Bersihkan layar
        cout << "Menu Hapus Node\n===============\n";
        cout << "1. Hapus Node di Depan\n2. Hapus Node di Belakang\n3. Hapus Node di Tengah\n4. Batal\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: // Hapus node di depan
                hapusNodeDepan();
                break;
            case 2: // Hapus node di belakang
                hapusNodeBelakang();
                break;
            case 3: // Hapus node di tengah
                cout << "Masukkan nilai yang akan dihapus: ";
                cin >> nilai;
                hapusNodeTengah(nilai); // Panggil fungsi
                break;
            case 4: // Batal
                break;
            default: // Pilihan tidak valid
                cout << "Pilihan tidak valid!\n";
        }
        system("read -p 'Press Enter to continue...' var"); // Tunggu input
    } while (pilihan != 4); // Ulangi hingga batal
}

int main() {
    int pilihan, nilai;

    do {
        system("clear"); // Bersihkan layar
        cout << "Menu:\n1. Buat Node Baru\n2. Tambah Node\n3. Hapus Node\n4. Tampilkan Seluruh Node\n5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1: // Buat node baru
                if (head == nullptr) {
                    cout << "Buat Node Baru\n==============\n";
                    cout << "Masukkan nilai: ";
                    cin >> nilai;
                    buatNodeAwal(nilai); // Panggil fungsi
                } else {
                    cout << "Node awal sudah dibuat!\n"; // Jika sudah ada node
                }
                break;
            case 2: // Menu tambah node
                menuTambahNode();
                break;
            case 3: // Menu hapus node
                menuHapusNode();
                break;
            case 4: // Tampilkan seluruh node
                tampilData();
                break;
            case 5: // Keluar dari program
                cout << "Keluar dari program.\n";
                break;
            default: // Pilihan tidak valid
                cout << "Pilihan tidak valid!\n";
        }
        system("read -p 'Press Enter to continue...' var"); // Tunggu input
    } while (pilihan != 5); // Ulangi hingga keluar

    return 0; // Akhir program
}
