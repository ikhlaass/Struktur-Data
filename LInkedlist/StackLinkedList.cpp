#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Data " << value << " ditambahkan ke stack.\n";
    }

void pop() {
        if (top == nullptr) {
            cout << "Stack underflow!\n";
        } else {
            Node* temp = top;
            cout << "Data " << top->data << " dihapus dari stack.\n";
            top = top->next;
            delete temp;
    }
}

void peek() {
        if (top == nullptr) {
            cout << "Stack kosong!\n";
        } else {
            cout << "Elemen teratas stack: " << top->data << endl;
        }
    }

void display() {
        if (top == nullptr) {
            cout << "Stack kosong!\n";
        } else {
            cout << "Isi stack: ";
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }


int main() {
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.peek();
    stack.display();

    return 0;
}
