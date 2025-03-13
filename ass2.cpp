#include <iostream>
#include <string>
using namespace std;

struct Node {
    int nim;
    string nama;
    string alamat;
    Node* next;
};

Node* head = nullptr;

void buatNodeAwal(int nim, string nama, string alamat) {
    head = new Node();
    head->nim = nim;
    head->nama = nama;
    head->alamat = alamat;
    head->next = nullptr;
    cout << "Data berhasil dimasukkan di node awal\n";
}

void hapusNodeDepan() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    } 

    Node* temp = head;
    head = head->next;
    cout << "Node pada posisi depan dengan NIM " << temp->nim << " berhasil dihapus\n";
    delete temp;
}

void hapusNodeBelakang() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "Node pada posisi belakang dengan NIM " << head->nim << " berhasil dihapus\n";
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << "Node pada posisi belakang dengan NIM " << temp->next->nim << " berhasil dihapus\n";
        delete temp->next;
        temp->next = nullptr;
    }
}

void tampilData() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << "NIM: " << temp->nim << endl;
        cout << "Nama: " << temp->nama << endl;
        cout <<  "Alamat: " << temp->alamat << endl << endl;
        temp = temp->next;
    }
    cout << "NULL\n";
}

void menuHapusNode() {
    int pilihan;
    do {
        cout << "\nMenu Hapus Node\n===============\n";
        cout << "1. Hapus Node di Depan\n2. Hapus Node di Belakang\n3. Batal\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                hapusNodeDepan();
                break;
            case 2:
                hapusNodeBelakang();
                break;
            case 3:
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 3);
}

int main() {
    int pilihan, nim;
    string nama, alamat;

    do {
        cout << "\nMenu:\n1. Buat Node Awal\n2. Hapus Node\n3. Tampil Data\n4. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Untuk mengabaikan newline setelah input pilihan

        switch (pilihan) {
            case 1:
                if (head == nullptr) {
                    cout << "Masukkan NIM: ";
                    cin >> nim;
                    cin.ignore();
                    cout << "Masukkan Nama: ";
                    getline(cin, nama);
                    cout << "Masukkan Alamat: ";
                    getline(cin, alamat);
                    buatNodeAwal(nim, nama, alamat);
                } else {
                    cout << "Node awal sudah dibuat!\n";
                }
                break;
            case 2:
                menuHapusNode();
                break;
            case 3:
                tampilData();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
