#include <iostream>
using namespace std;
class LinkedList {
private:
    int data;
    LinkedList* next;

public:
    LinkedList(int val) {
        data = val;
        next = nullptr;
    }

    // Insert a node at the end of the list
    void insert(int val) {
        LinkedList* new_node = new LinkedList(val);

        LinkedList* current = this;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    // Insert a node at a specific position in the list
    void insertAt(int val, int pos) {
        LinkedList* new_node = new LinkedList(val);

        if (pos == 1) {
            new_node->next = this;
            data = val;
        }
        else {
            LinkedList* current = this;
            for (int i = 1; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current == nullptr) {
                cout << "Invalid position" << endl;
                return;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

    // Display the list
    void display() {
        LinkedList* current = this;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList* head = new LinkedList(1);
    head->insert(2);
    head->insert(3);
    head->insert(4);
    head->insert(5);
    cout << "Original list:" << endl;
    head->display();

    head->insertAt(6, 3);
    cout << "After inserting 6 at position 3:" << endl;
    head->display();

    head->insertAt(7, 1);
    cout << "After inserting 7 at position 1:" << endl;
    head->display();

    head->insertAt(8, 8);
    cout << "After inserting 8 at position 8:" << endl;
    head->display();

    return 0;
}
