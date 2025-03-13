#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
} *head;

int isEmpty() {
    return head == NULL;
}

void insertDepan(int dataBaru) {
    node *baru = new node;
    baru->data = dataBaru;
    baru->next = NULL;

    if (isEmpty()) {
        head = baru;
    } else {
        baru->next = head;
    }
    head = baru;

    cout << "Data Masuk" << endl;
    system("read");
    system("clear");
}

void insertBelakang(int dataBaru) {
    node *baru = new node;
    baru->data = dataBaru;
    baru->next = NULL;

    if (isEmpty()) {
        head = baru;
    } else {
        node *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }

    cout << "Data Masuk" << endl;
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void hapusDepan() {
    if (!isEmpty()) {
        node *hapus = head;
        head = head->next;
        delete hapus;
        cout << "Terhapus" << endl;
    } else {
        cout << "Data Masih Kosong" << endl;
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void hapusBelakang() {
    if (!isEmpty()) {
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            node *bantu = head;
            while (bantu->next->next != NULL) {
                bantu = bantu->next;
            }
            delete bantu->next;
            bantu->next = NULL;
        }
        cout << "Data Terhapus" << endl;
    } else {
        cout << "Data Masih Kosong" << endl;
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void tampilkan() {
    if (!isEmpty()) {
        node *bantu = head;
        while (bantu != NULL) {
            cout << "| " << bantu->data << " | ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "Data Masih Kosong" << endl;
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

int main() {
    system("clear");
    int pil, dataBaru;

    do {
        cout << "====================" << endl;
        cout << "1. Insert Depan" << endl;
        cout << "2. Insert Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> pil;

        switch (pil) {
            case 1:
                cout << "Masukkan Data Baru: ";
                cin >> dataBaru;
                insertDepan(dataBaru);
                break;
            case 2:
                cout << "Masukkan Data Baru: ";
                cin >> dataBaru;
                insertBelakang(dataBaru);
                break;
            case 3:
                hapusDepan();
                break;
            case 4:
                hapusBelakang();
                break;
            case 5:
                tampilkan();
                break;
            case 6:
                cout << "Terima Kasih" << endl;
                break;
            default:
                cout << "Pilihan Yang Anda Masukkan Tidak Valid" << endl;
                break;
        }
    } while (pil >= 1 && pil <= 5);

    return 0;
}
