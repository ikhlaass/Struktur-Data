#include <iostream>
using namespace std;

#define MAX 5

struct Stack {
    int data[MAX];
    int top;
} tumpukan;

void inisialisasi() {
    tumpukan.top = -1;
}

bool IsEmpty() {
    return tumpukan.top = -1;
}

bool IsFull() {
    return tumpukan.top = MAX - 1;
}

void push(int data) {
    if (IsFull()) {
        cout << "Stack sudah penuh!" << endl;
    } else {
        tumpukan.top++;
        tumpukan.data[tumpukan.top] = data;
        cout << "Data " << data << " berhasil dimasukkan..." << endl;
    }
}

void pop() {
    if (IsEmpty()) {
        cout << "Stack kosong, pop dibatalkan..." << endl;
    } else {
        cout << "Data " << tumpukan.data[tumpukan.top] << " berhasil dikeluarkan..." << endl;
        tumpukan.top--;
    }
}

void tampilkan() {
    if (IsEmpty()) {
        cout << "Stack masih kosong..." << endl;
    } else {
        cout << "Isi stack mulai dari posisi top: " << endl;
        for (int i = tumpukan.top; i >= 0; i--) {
            cout << tumpukan.data[i] << " " << endl;
        }
        cout << endl;
    }
}


int main() {
    system("clear");
    int pilih, input;

    inisialisasi(); 
    do {
        cout << "Implementasi Stack Dengan Array" << endl;
        cout << "==================================" << endl;
        cout << "Menu : " << endl;
        cout << "1. Push data" << endl;
        cout << "2. Pop data" << endl;
        cout << "3. Tampil isi stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan [1..5] : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan data: ";
                cin >> input;
                push(input);
                break;
            case 2:
                pop();
                break;
            case 3:
                tampilkan();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        cout << endl;
    } while (pilih != 5);

    return 0;
}
