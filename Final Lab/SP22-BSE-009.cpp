#include <iostream>
#include<string>
using namespace std;
class Node {
public:
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int data) {
        value = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};
class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    // Get the height of a node
    int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
         return getHeight(node->left)-getHeight(node->right);
    }

    // Perform right rotation
    Node* rightRotate(Node* z) {
        Node* y = z->left;
        Node* T3 = y->right;

        y->right = z;
        z->left = T3;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    // Perform left rotation
    Node* leftRotate(Node* z) {
        Node* y = z->right;
        Node* T2 = y->left;

        y->left = z;
        z->right = T2;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }


    // Insert a node into the AVL tree
    Node* insertion(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->value)
            node->left = insertion(node->left, value);
        else
            node->right = insertion(node->right, value);

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    void inOrderTraversal(Node *node)
    {
        if(node)
        {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }
    void PreOrderTraversal(Node *node)
    {
        if(node){
        cout << node->value << " ";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
        }
    }
    void PostOrderTraversal(Node *node)
    {
        if(node)
        {
        PostOrderTraversal(node->left);
        PostOrderTraversal(node->right);
        cout << node->value << " ";
        }
    }
};
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
         {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex!=i)
        {
            swap(arr[i],arr[minIndex]);
        }
    }
}
class Queues
{
private:
    class Node
    {
    public:
        string data;
        Node *next;
        Node (string d)
        {
            data=d;
            next=NULL;
        }
    };
    Node *frontt;
    Node *backk;
    public:
        Queues ()
        {
            frontt=NULL;
            backk=NULL;
        }
        void push(string val)
        {
            Node *temp=new Node(val);
            if (frontt==NULL)
            {
                backk=temp;
                frontt=temp;
                return;
            }
            backk->next=temp;
            backk=temp;
        }
        void pop()
        {
            if (frontt==NULL)
            {
                cout << "Queue Underflow..";
                return;
            }
            Node *temp=frontt;
            frontt=frontt->next;
            delete temp;
        }
        int top()
        {
            if (frontt==NULL)
            {
                cout << "NO VALUE IN QUEUE..";
                return -1;
            }
           // return frontt->data;
        }
};
       int main()
       {
        int choice;
        cout << "Which Program do you want to run: (1 for AvlTree, 2 for Selection Sort, 3 for Queues: ";
        cin >> choice;
        if (choice ==1)
        {
                AVLTree avlTree;
                int numNodes;
                cout << "Enter the number of nodes to insert: ";
                cin >> numNodes;
                cout << "Enter the values to insert: ";
                for (int i = 0; i < numNodes; i++) {
                    int value;
                    cin >> value;
                    avlTree.root = avlTree.insertion(avlTree.root, value);
                }
                        cout << "Inorder traversal of the AVL tree: ";
                        avlTree.inOrderTraversal(avlTree.root);
                        cout << endl;
                        cout << "PreOrderTraversal of AVL Tree is: ";
                        avlTree.PreOrderTraversal(avlTree.root);
                        cout << endl;
                        cout << "Post Order Traversal of AVL Tree is: ";
                        avlTree.PostOrderTraversal(avlTree.root);

        }
        if (choice==2)
    {
            int n;
            cout << "Enter the number of elements: ";
            cin >> n;
            int arr[n];
            cout << "Enter the elements of array: ";
            for (int i=0;i<n;i++)
            {
                cin >> arr[i];
            }
            cout << "Sorted Array is: ";
            selectionSort(arr,n);
            for (int j=0;j<n;j++)
            {
                cout << arr[j] << " ";
            }
        }
        if (choice==3)
        {
            Queues q1;
            q1.push("The Great Gatsby");
            q1.push("To Kill MockingBird");
            q1.push("The Lord of the Rings");
            q1.pop();
       }
       }
