#include <iostream>
using namespace std;

struct Dosen {
    string nama;
    string NIP;
    string alamat;
    Dosen* prev;
    Dosen* next;
};

class DoubleLinkedList {
private:
    Dosen* head;
    Dosen* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahPertamaKali(string nama, string NIP, string alamat) {
        Dosen* newNode = new Dosen();
        newNode->nama = nama;
        newNode->NIP = NIP;
        newNode->alamat = alamat;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void tambahPosisiTerakhir(string nama, string NIP, string alamat) {
        Dosen* newNode = new Dosen();
        newNode->nama = nama;
        newNode->NIP = NIP;
        newNode->alamat = alamat;
        newNode->next = nullptr;

        if (tail == nullptr) {
            head = tail = newNode;
            newNode->prev = nullptr;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void tambahPosisiTengah(string nama, string NIP, string alamat) {
        if (head == nullptr || head->next == nullptr) {
            cout << "Data tidak cukup untuk menambah di posisi tengah." << endl;
            return;
        }

        Dosen* newNode = new Dosen();
        newNode->nama = nama;
        newNode->NIP = NIP;
        newNode->alamat = alamat;

        Dosen* slow = head;
        Dosen* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            if (fast != nullptr) {
                slow = slow->next;
            }
        }

        newNode->next = slow->next;
        newNode->prev = slow;

        if (slow->next != nullptr) {
            slow->next->prev = newNode;
        }
        slow->next = newNode;
    }

    void hapusPosisiTerdepan() {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }
        
        Dosen* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    void hapusPosisiTerakhir() {
        if (tail == nullptr) {
            cout << "List kosong." << endl;
            return;
        }

        Dosen* temp = tail;
        tail = tail->prev;
        
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }

    void hapusPosisiTengah() {
    if (head == nullptr || head->next == nullptr) {
        cout << "Data tidak cukup untuk menghapus di posisi tengah." << endl;
        return;
    }

    Dosen* slow = head;
    Dosen* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow->prev != nullptr) {
        slow->prev->next = slow->next;
    }
    if (slow->next != nullptr) {
        slow->next->prev = slow->prev;
    }
    if (slow == head) {
        head = slow->next;
    }
    if (slow == tail) {
        tail = slow->prev;
    }
    delete slow;

}

    void tampilkanDariDepan() {
        if (head == nullptr) {
            cout << "List kosong." << endl;
            return;
        }

        Dosen* temp = head;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << endl;
            cout << "NIP: " << temp->NIP << endl;
            cout << "Alamat: " << temp->alamat << endl << endl;
            temp = temp->next;
        }
    }

    void tampilkanDariBelakang() {
        if (tail == nullptr) {
            cout << "List kosong." << endl;
            return;
        }

        Dosen* temp = tail;
        while (temp != nullptr) {
            cout << "Nama: " << temp->nama << endl;
            cout << "NIP: " << temp->NIP << endl;
            cout << "Alamat: " << temp->alamat << endl<< endl;
            temp = temp->prev;
        }
    }
};

int main() {
    DoubleLinkedList daftarDosen;
    int pilihan;
    string nama, NIP, alamat;
    
    cout << "Nama\t: Rezki" << endl;
    cout << "Stambuk\t: 13020230139" << endl;
    cout << "=======================" << endl;

    do {
        cout << "\nProgram Daftar Dosen UMI" << endl;
        cout << "1. Buat Node Awal" << endl;
        cout << "2. Tambah Dosen" << endl;
        cout << "3. Hapus Dosen" << endl;
        cout << "4. Tampilkan List Data Dosen" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan [1...5]: ";
        cin >> pilihan;
        cin.ignore(); // Menjaga agar buffer input bersih

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan NIP: ";
                getline(cin, NIP);
                cout << "Masukkan Alamat: ";
                getline(cin, alamat);
                daftarDosen.tambahPertamaKali(nama, NIP, alamat);
                break;
            case 2:
                int subPilihan;
                cout << "1. Pertama kali\n2. Posisi terakhir\n3. Posisi tengah\nPilih posisi: ";
                cin >> subPilihan;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan NIP: ";
                getline(cin, NIP);
                cout << "Masukkan Alamat: ";
                getline(cin, alamat);
                if (subPilihan == 1)
                    daftarDosen.tambahPertamaKali(nama, NIP, alamat);
                else if (subPilihan == 2)
                    daftarDosen.tambahPosisiTerakhir(nama, NIP, alamat);
                else if (subPilihan == 3)
                    daftarDosen.tambahPosisiTengah(nama, NIP, alamat);
                else
                    cout << "Pilihan tidak valid." << endl;
                break;
            case 3:
                cout << "1. Posisi terdepan\n2. Posisi terakhir\n3. Posisi tengah\nPilih posisi: ";
                cin >> subPilihan;
                cin.ignore();
                if (subPilihan == 1)
                    daftarDosen.hapusPosisiTerdepan();
                else if (subPilihan == 2)
                    daftarDosen.hapusPosisiTerakhir();
                else if (subPilihan == 3)
                    daftarDosen.hapusPosisiTengah();
                else
                    cout << "Pilihan tidak valid." << endl;
                break;
            case 4:
                cout << "1. Dari depan\n2. Dari belakang\nPilih tampilan: ";
                cin >> subPilihan;
                cin.ignore();
                if (subPilihan == 1)
                    daftarDosen.tampilkanDariDepan();
                else if (subPilihan == 2)
                    daftarDosen.tampilkanDariBelakang();
                else
                    cout << "Pilihan tidak valid." << endl;
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}