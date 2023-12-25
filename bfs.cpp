#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int data)
{
    Node *newNode=new Node();
    if (!newNode)
    {
        cout << "Memory alloc failed..";
        return nullptr;
    }
    newNode->data=data;
    newNode->left=newNode->right=nullptr;
    return newNode;
}
void BFS(Node *root)
{
    if(root==nullptr)
        return;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node *current=q.front();
        cout << current->data <<" ";
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
        q.pop();
    }
}
int main(){
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Breadth First Search: ";
    BFS(root);
    cout << endl;
}
