#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* buatNode(int data) {
    Node* nodeBaru = new Node();
    nodeBaru->data = data;
    nodeBaru->kiri = nullptr;
    nodeBaru->kanan = nullptr;
    return nodeBaru;
}

Node* tambah(Node* akar, int data) {
    if (akar == nullptr) {
        return buatNode(data);
    }
    if (data < akar->data) {
        akar->kiri = tambah(akar->kiri, data); 
    } else if (data > akar->data) {
        akar->kanan = tambah(akar->kanan, data); 
    }
    return akar;
}

bool cari(Node* akar, int kunci) {
    if (akar == nullptr) {
        return false; 
    }
    if (akar->data == kunci) {
        return true; 
    }
    if (kunci < akar->data) {
        return cari(akar->kiri, kunci); 
    }
    return cari(akar->kanan, kunci);
}

Node* cariMin(Node* akar) {
    while (akar->kiri != nullptr) {
        akar = akar->kiri;
    }
    return akar;
}

Node* hapus(Node* akar, int kunci) {
    if (akar == nullptr) {
        return akar; 
    }
    if (kunci < akar->data) {
        akar->kiri = hapus(akar->kiri, kunci); 
    } else if (kunci > akar->data) {
        akar->kanan = hapus(akar->kanan, kunci); 
    } else {
        if (akar->kiri == nullptr) {
            Node* temp = akar->kanan;
            delete akar;
            return temp;
        } else if (akar->kanan == nullptr) {
            Node* temp = akar->kiri;
            delete akar;
            return temp;
        }

        Node* temp = cariMin(akar->kanan); 
        akar->data = temp->data; 
        akar->kanan = hapus(akar->kanan, temp->data); 
    }
    return akar;
}

void inOrder(Node* akar) {
    if (akar != nullptr) {
        inOrder(akar->kiri); 
        cout << akar->data << " "; 
        inOrder(akar->kanan); 
    }
}

int main() {
    Node* akar = nullptr;
    int pilihan, data;

    do {
        cout << "Menu Binary Search Tree BST:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. In-Order Traversal\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Pilihan (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan elemen yang ingin di tambahkan: ";
            cin >> data;
            akar = tambah(akar, data);
            cout << "Data " << data << "berhasil ditambahkan";
            break;
        case 2:
            cout << "Masukkan elemen yang ingin dihapus: ";
            cin >> data;
            akar = hapus(akar, data);
            break;
        case 3:
            cout << "Masukkan elemen yang ingin dicari: ";
            cin >> data;
            if (cari(akar, data)) {
                cout << "Data " << data << "ditemukan dalam BST.\n";
            } else {
                cout << "Elemen tidak ditemukan.\n";
            }
            break;
        case 4:
            cout << "In-Order Trversal";
            inOrder(akar);
            cout << endl;
            break;
        case 5:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
