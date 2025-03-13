#include <iostream>
using namespace std;

const int MAX = 5;

struct queue {
    string data[MAX];
    int front;
    int rear = -1;
}antrian;

void enQueue(string data) {
    antrian.rear++;
    antrian.data[antrian.rear] = data;
}

void deQueue() {
    antrian.front++;
}

void tampilkan() {
    for(int i = antrian.front; i <= antrian.rear; i++) {
        cout << "Data Di Dalam Antrian :" << antrian.data[i] << endl;
    }
}

int main() {
    system("clear");
    string nama;
    int pil;

    do {
        cout << "Menu:\n";
        cout << "1. enQueue\n";
        cout << "2. deQueue\n";
        cout << "3. Tampilkan\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi (1/2/3/4): ";
        cin >> pil;

        switch (pil) {
            case 1:
                cin.ignore(); 
                    cout << "Masukkan Nama: ";
                    getline(cin, nama);
                    enQueue(nama);
                break;
            case 2:
                deQueue();
                break;
            case 3: 
                tampilkan();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pil != 4);

    return 0;
}