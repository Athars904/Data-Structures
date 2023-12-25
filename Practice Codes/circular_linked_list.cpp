#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data)
{
    Node* n = new Node(data);
    n->next = head;
    tail->next = n;
    head = n;
    return;
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    Node* n = new Node(data);
    tail->next = n;
    n->next = head;
    tail = n;
    return;
}

void traverse(Node* head, Node* tail)
{
    if(head->next == tail->next)
    {
        cout << head->data << " -> REPEAT";
        return;
    }
    cout << head->data << " -> ";
    traverse(head->next,tail);
    return;
}

void deleteNode(Node* &head, Node* &tail, int index)
{
    Node* temp = head;
    Node* prev = nullptr;
    for(int i = 0; i < index; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    if(temp == tail)
        tail = prev;
    else if(temp == head)
        head = temp->next;
    delete temp;
    return;
}

int main()
{
    Node* head = new Node(5);
    Node* tail = head;
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,1);
    insertAtTail(head,tail,7);
    insertAtTail(head,tail,9);
    deleteNode(head,tail,2);
    traverse(head,tail);

    return 0;
}
