#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data = 0)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

int listLength(Node* head,Node* tail)
{
    if(head == tail)
        return 1;
    int SA = listLength(head->next,tail);
    int len = SA + 1;
    return len;
}

void insertAtHead(Node* &head, int data)
{
    Node* n = new Node(data);
    n->next = head;
    head->prev = n;
    head = n;
    return;
}

void insertAtTail(Node* &tail, int data)
{
    Node* n = new Node(data);
    n->prev = tail;
    tail->next = n;
    tail = n;
    return;
}

void deleteNode(Node* &head, Node* &tail, int index)
{
    Node* temp;
    if(index == 0)
    {
        temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return;
    }
    else if(index == (listLength(head,tail)-1))
    {
        temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        return;
    }
    else if(index < 0 || index >= (listLength(head,tail)))
    {
        cout << "index out of range!\n";
    }
    else
    {
        temp = head;
        for(int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        return;
    }
}

void traverseForward(Node* head)
{
    if(!head)
    {
        cout << "NULL\n";
        return;
    }
    cout << head->data << " -> ";
    traverseForward(head->next);
    return;
}

void traverseBackward(Node* tail)
{
    if(!tail)
    {
        cout << "NULL\n";
        return;
    }
    cout << tail->data << " -> ";
    traverseBackward(tail->prev);
    return;
}

int main()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* n = new Node(5);
    head = n;
    tail = n;
    insertAtHead(head,3);
    //insertAtTail(tail,7);
    insertAtHead(head,1);
    //insertAtTail(tail,9);
    traverseForward(head);
    //deleteNode(head,tail,0);
    //deleteNode(head,tail,1);
    //deleteNode(head,tail,2);
    traverseBackward(tail);
    cout << listLength(head,tail);
    return 0;
}
