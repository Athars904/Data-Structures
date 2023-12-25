#include<iostream>
using namespace std;
class LinkedList
{
private:
    int data;
    LinkedList *next;
    LinkedList(int val)
    {
        data=val;
        next=NULL;
    }
public:

    LinkedList *head, *tail;
    int size;
    LinkedList()
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
    void insertatHead(int d)
    {
        LinkedList *temp=new LinkedList(d);
        if(isEmpty())
        {
            head=temp;
            tail=head;
        } 
        else
        {
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertatTail(int d)
    {
        LinkedList *temp=new LinkedList(d);
        if(isEmpty())
        {
            head=temp;
            tail=temp;
        }
        else 
        {
            tail->next=temp;
            tail=tail->next;
        }
        size++;
    }
    void insertatPosition(int d, int pos)
    {
        if (isEmpty())
        {
            cout << "Position is empty " << endl;
            return;
        }
        if (pos>size||pos<0)
        {
            cout << "Invalid position...." << endl;
            return;
        }
        if (pos==1)
        {
            insertatHead(d);
            return;
        }
        if (pos==size)
        {
            insertatTail(d);\
            return;
        }
        LinkedList *temp=new LinkedList(d);
        LinkedList *p=head;
        for (int i=0;true;i++)
        {
            if (i==pos)
            {
                temp->next=p->next;
                p->next=temp;
                size++;
                return;
            }
            p=p->next;
        }
    }
    void deleteNode(int pos)
    {
        if (pos==1)
        {
            LinkedList *temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            size--;
        }
        else 
        {
            LinkedList *curr=head;
            LinkedList *prev=NULL;
            int c=1;
            while (c<pos)
            {
                prev=curr;
                curr=curr->next;
                c++;
            }
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
            size--;
        }
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "LinkedList is Empty" << endl;
            return;
        }
        else
        {
            LinkedList *temp=head;
            while (temp!=NULL)
            {
                cout << temp->data << "  ";
                temp=temp->next;
            }
            cout << "SIZE= " << size;
        }
    }


};
int main()
{
    LinkedList List;
    List.print();
    cout << "Creating a list" << endl;
    List.insertatHead(5);
    List.insertatTail(10);
    List.insertatHead(7);
    List.insertatPosition(56,3);
    List.insertatPosition(-1,1);
    List.insertatPosition(55,2);
    List.deleteNode(2);
    List.print();
}