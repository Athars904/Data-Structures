#include<iostream>
using namespace std;
class Node
{
    private:
    int Data;
    Node *Next;
    public:
    Node(int x)
    {
        Data=x;
        Next=NULL;
    }
    Node *head,*tail;
    int size;
    Node()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    bool isEmpty()
    {
        if (head==NULL)
        {
            return true;
        }
        return false;
    }
    void insertatHead(int x)
    {
        Node *temp=new Node(x);
        if (isEmpty())
        {
            head=temp;
            tail=head;
        }
        else
        {
        temp->Next=head;
        head=temp;
        }
        size++;
    }
    void insertatTail(int x)
    {
        Node *temp=new Node(x);
        if (isEmpty())
        {
            head=temp;
            tail=head;
        }
        else
        {
        tail->Next=temp;
        tail=tail->Next;
        }
        size++;
    }
    void print()
    {
        Node *temp=head;
        while (temp!=NULL)
        {
            cout << temp->Data << " -> ";
            temp=temp->Next;
        }
        cout << "SIZE OF LIST IS : " << size;
    }
};
int main()
{
    Node list;
    list.insertatHead(5);
    list.insertatHead(6);
    list.insertatHead(7);
    list.insertatTail(8);
    list.print();
    return 0;
}

