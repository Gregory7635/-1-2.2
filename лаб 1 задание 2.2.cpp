#include <iostream>
#include <string>
using namespace std;

struct Node {
public:
    string val;
    Node* next;
    Node(string value) {
        val = value;
        next = nullptr;
    }
};

struct turn {
    int Size = 0;
    Node* first;

    turn() {
        first = nullptr;
    }
    bool is_empty() {
        return first == nullptr;
    }

    void push(string value) {
        if (first == nullptr) {
            first = new Node(value);
        }
        else {
            Node* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);

        }
        Size++;
    }
    void pop() {
        
         Node* previous = nullptr;
         Node* current = first;
         while (current->next != nullptr) {
              previous = current;
              current = current->next;
            }

         previous->next = nullptr;
        
        Size = Size - 1;
    }
    void print() {
        if (is_empty() == true) {
            first = nullptr;
        }
        Node* current = first;
        while (current) {
            cout << current->val << " " << endl;
            current = current->next;
        }
        cout << endl;

    }
    int GetSize() {
        return Size;
    }
    Node* operator[] (const int index) {
        Node* current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    turn l;
    l.push("Students");
    l.push("of");
    l.push("the");
    l.push("group");
    l.push("TE");
    l.push("3");
    cout << "Первый вызов" << endl;
    l.print();
    l.pop();
    cout << "Второй вызов" << endl;
    l.print();
    cout << "строки, которые состоят из двух символов из стека" << endl;
    for (int i = 0; i < l.GetSize(); i += 1) {
        if (l[i]->val.size() == 2) {
            cout << l[i]->val << ";";
        }
    }
}