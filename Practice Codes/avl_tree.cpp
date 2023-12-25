//AVL Tree Data 35,50,40,25,30,60,78,20,28
#include<iostream>
using namespace std;
class Node
{
public:

    int value;
    Node *left;
    Node *right;
    int height;
    Node(int d)
    {
        value=d;
        left=nullptr;
        right=nullptr;
        height=1;
    }

};
class AvlTree
{
public:
    Node *root;
    AvlTree()
    {
        root=nullptr;
    }
      int getHeight(Node* node) {
        if (node == nullptr)
            return 0;
            return node->height;
            }

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    Node *rightRotate(Node *z)
    {
        Node *y=z->left;
        Node *T3=z->right;
        y->right=z;
        z->left=T3;
        z->height=1+max(getHeight(z->left),getHeight(z->right));
        y->height=1+max(getHeight(y->left),getHeight(y->right));
        return y;
    }
    Node *leftRotate(Node *z)
    {
        Node *y=z->right;
        Node *T2=y->left;
        y->left=z;
        z->right=T2;
        z->height=1+max(getHeight(z->left),getHeight(z->right));
        y->height=1+max(getHeight(y->left),getHeight(y->right));
        return y;
    }
    Node *insertion(Node *node, int value)
    {
        if (node==nullptr)
            return new Node(value);
        if (value<node->value)
            node->left=insertion(node->left,value);
        else
        node->right=insertion(node->right,value);
        node->height=1 + max(getHeight(node->left),getHeight(node->right));
        int balance=getBalance(node);
        //LL
        if (balance>1 && value<node->left->value)
            return rightRotate(node);
            //RR
        if (balance<-1&&value>node->right->value)
            return leftRotate(node);
            //LR
        if (balance>1 && value>node->left->value)
        {
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
        //RL
        if (balance<-1&& value<node->right->value)
        {
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
     void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
     }
};
int main()
{
    AvlTree avlTree;
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
    avlTree.inorder(avlTree.root);
    return 0;
}
