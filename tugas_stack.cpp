#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

int main() {
    Node* top = nullptr;
    string kata;

    cout << "Masukkan kata: ";
    cin >> kata;

    for (char c : kata) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    cout << "hasil kata setelah dibalik: ";
    while (top != nullptr) {
        cout << top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    cout << endl;

}