#include<iostream>
using namespace std;
class Stack
{
    class Node
    {
        public:
        int data;
        Node *next;
        Node(int d)
        {
            data=d;
            next=NULL;
        }
    };
    int size;
    Node *head;
    public:
    Stack()
    {
        head=NULL;
        size=0;
    }
    bool isEmpty()
    {
        if(head==NULL)
            return true;
        return false;
    }
    void push(int ele)
    {
        Node *temp=new Node(ele);
        temp->next=head;
        head=temp;
        size++;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty...";
            return;
        }
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        size--;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty...";
            return -1;
        }
        return head->data;
    }
    int size()
    {
        return size;
    }
};
int main()
{
    Stack s;
    s.push(5);
    s.push(56);
    s.push(34);
    s.push(34);
    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}
