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
    }
    int siz;
    Node *head;
    public:
    Stack()
    {
        siz=0;
        head=NULL;
    }
    void push(int ele)
    {
        Node *temp=new Node(ele);
        temp->next=head;
        head=temp;
        siz++;
    }
    void pop()
    {
        Node *temp=head;
        head=temp->next;
        delete temp;
        siz--;
    }
}
int main()
{

}