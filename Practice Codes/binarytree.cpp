#include <iostream>
#include <cmath>
#include<math.h>
using namespace std;
class Binary_Tree {
private:
    int* arr;
    int capacity;
public:
    Binary_Tree(int size) {
        arr = new int[size + 1];
        capacity = size;
        for (int i = 1; i <= capacity; i++) {
            arr[i] = 0;
        }
    }

    void insert(int value) {
        if (arr[1] == 0) {
            arr[1] = value;
            return;
        }

        for (int i = 1; i <= capacity; i++) {
            if (arr[i] == 0) {
                arr[i] = value;
                return;
            }
        }
    }

    void display() {
        for (int i = 1; i <= capacity; i++) {
            if (arr[i] != 0) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    int parent(int index) {
        return arr[floor(index/2)];
    }

    int leftChild(int index) {
        return arr[2*index];
    }

    int rightChild(int index) {
        return arr[2*index+1];
    }
};

int main() {
    Binary_Tree tree(10);

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);

    tree.display(); // output: 1 2 3 4 5 6 7

    cout << "Parent of index 4: " << tree.parent(4) << endl; // output: 2
    cout << "Left child of index 2: " << tree.leftChild(2) << endl; // output: 4
    cout << "Right child of index 2: " << tree.rightChild(2) << endl; // output: 5

    return 0;
}

