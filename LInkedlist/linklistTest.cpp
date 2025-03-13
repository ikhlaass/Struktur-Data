#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
} *head;

bool isEmpty() {
    return head == NULL;
}

void insertDepan(int dataBaru) {
    Node *baru = new Node;
    baru->data = dataBaru;
    baru->next = NULL;

    if(isEmpty()) {
        head = baru;
    }else {
        baru->next = head;
    }
    head = baru;
}

void insertBelakang(int dataBaru) {
    Node *baru = new Node;
    baru->data = dataBaru;
    baru->next = NULL;
    
    if(isEmpty()) {
        head = baru;
    }else {
        Node *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void tampilkan() {
    Node *bantu = head;  
        while (bantu != NULL) {
            cout << bantu->data << " ";  
            bantu = bantu->next;  
        }
}

int main() {
    insertBelakang(15);
    insertDepan(17);
    insertBelakang(20);

    tampilkan();
}