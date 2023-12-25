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
    void insertatPosition(int x, int pos)
    {
        if(pos==1)
        {
            insertatHead(x);
            return;
        }
        if (pos>size||pos<0)
        {
            cout << "Invalid Position.";
            return;
        }
        if (pos==size)
        {
            insertatTail(x);
            return;
        }
        Node *temp=new Node(x);
        Node *p=head;
        for (int i=0;true;i++)
        {
            if(i==pos)
            {
                temp->Next=p->Next;
                p->Next=temp;
                size++;
                return;
            }
            p=p->Next;
        }
    }
    void deletenode(int pos)
    {
        if (pos==1)
        {
            Node *temp=head;
            head=head->Next;
            temp->Next=NULL;
            delete temp;
            size--;
        }
        else{
            Node *curr=head;
            Node *prev=NULL;
            int count=1;
            while (count<pos)
            {
                prev=curr;
                curr=curr->Next;
                count++;
            }
            prev->Next=curr->Next;
            curr->Next=NULL;
            delete curr;
            size--;
        }
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
    list.insertatPosition(3,2);
    list.deletenode(4)
    list.print();
    return 0;
}
