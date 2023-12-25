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
    void print()
    {
        LinkedList  *temp=head;
        if (isEmpty())
        {
            cout << "List is empty...";
            return;
        }
        while (temp!=NULL)
        {
            cout << temp->data << " -> ";
            temp=temp->next;
        }
        cout << " NULL";
    }
};
class Stack
{
    class NodeS
    {
        public:
        int Data;
        NodeS *Next;
        NodeS(int d)
        {
            Data=d;
            Next=NULL;
        }
    };
    int sizestack;
    NodeS *head;
    public:
    Stack()
    {
        sizestack=0;
    }
    bool isEmpty()
    {
        if(head==NULL)
        {
            return true;
        }
        return false;
    }
    void push(int ele)
    {
        if (isEmpty())
        {
            cout << "Stack is empty...";
            return;
        }
        NodeS *temp=new NodeS(ele);
        temp->Next=head;
        head=temp;
        sizestack++;
        return;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty....";
            return;
        }
        NodeS *temp=head;
        head=temp->Next;
        temp->Next=NULL;
        delete temp;
        sizestack--;
        return;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty...";
            return 0;
        }
        return head->Data;
    }
    int size()
    {
        return sizestack;
    }
};
int sumOdd(int num)
{
    if (num==0)
    {
        return 0;
    }
    int sum=0;
    sum=num+sumOdd(num-2);
    return sum;
}
int main()
{
    int choice;
    cout << "Which Program do you want to run? (1 for LinkedList, 2 for Stack, 3 for recursion) :" ;
    cin >> choice;
    if(choice==1)
    {
        LinkedList list1;
        list1.insertatHead(23);
        list1.insertatHead(342);
        list1.insertatTail(343);
        list1.insertatPosition(23,2);
        list1.print();
    }
    if (choice==2)
    {
        Stack s;
        int c;
        while (1)
        {
            cout << "What do you want to do?(1 to push, 2 to pop, 3 to top, 4 to terminate)";
            cin >> c;
            if (c==4)
            {
                break;
            }
            if (c==1)
            {
                cout << "Enter the element to push";
                int ele;
                cin >> ele;
                s.push(ele);
            }
            if (c==2)
            {
                s.pop();
            }
            if(c==3)
            {
               cout << s.top();
            }
        }
    }
    if (choice==3)
    {
        int n=20;
        cout << "The sum of first 10 odd numbers is: " << sumOdd(n);
    }
    return 0;
}
