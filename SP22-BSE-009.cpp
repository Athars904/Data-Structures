#include<iostream>
using namespace std;
class Node
{
    int data;
    Node* next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
    public:
    Node *head;
    int size=0;
    Node()
    {
        head=NULL;
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
        if (isEmpty())
        {
            cout << "List is empty";
            return;
        }
        Node *temp=new Node(d);
        temp->next=head;
        head=temp;
        size++;
    }
    void insertatPosition(int d, int pos)
    {
        if (isEmpty())
        {
            cout << "List is empty";
            return;
        } 
        if (pos==1)
        {
            insertatHead(d);
        }
        else
        {
            Node *temp=new Node(d);
            Node *p=head;
            for (int i=0;true;i++)
            {
                if(i==pos)
                {
                    temp->next=p->next;
                    p->next=temp;
                    size++;
                    return;
                }
                p=p->next;
            } 
        }
    }
    void print()
    {
        if(isEmpty())
        {
            cout << "LIST IS EMPTy...";
            return;
        }
        while (head!=NULL)
        {
            cout << head->data << "-> ";
            head->next;
        }
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
        head=NULL;
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
        head=head->Next;
        temp->Next=NULL;
        delete temp;
        return;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty...";
            return;
        }
        while (head->Next!=NULL)
        {
            cout << head->Data << " ";
            head=head->Next;
        }
    }
    int size()
    {
        return sizestack;
    }
};
int sumOdd()
{
    
}
int main()
{
    int choice;
    cout << "Which Program do you want to run? (1 for LinkedList, 2 for Stack, 3 for recursion)";
    cin >> choice;
    if(choice==1)
    {
        Node list;
        list.insertatHead(5);
        list.insertatHead(34);
        list.insertatHead(43);
        list.insertatPosition(23,2);
        list.print();
    }
    return 0;
}