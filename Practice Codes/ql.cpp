#include<iostream>
using namespace std;
class Queues
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int d)
        {
            data=d;
            next=nullptr;
        }
    };
    Node *fronnt;
    Node *bacck;
    public:
        Queues()
        {
            fronnt=nullptr;
            bacck=nullptr;

        }
        void push(int val) {
        Node *temp=new Node(val);
        if (fronnt==nullptr)
        {
            bacck=temp;
            fronnt=temp;
            return;
        }
        bacck->next=temp;
        bacck=temp;
        }
        void pop()
        {
            if (fronnt==nullptr)
            {
                cout << "Queue underflow";
                return;
            }
            Node *temp=fronnt;
            fronnt=fronnt->next;
            temp->next=nullptr;
            delete temp;
        }
                int top()
        {
            if (fronnt==NULL)
            {
                cout << "NO VALUE IN QUEUE..";
                return -1;
            }
            return fronnt->data;
        }
        void deletetion(int pos)
        {
            if(fronnt==nullptr)
            {
                cout << "NO DATA IN QUEUE...";
                return;
            }
            if (pos==1)
            {
                pop();
                return;
            }
            Node *curent=fronnt;
            for (int i=1;i<pos && curent!=nullptr;i++)
            {
                bacck=curent;
                curent=curent->next;
            }
            bacck->next=fronnt->next;
            delete curent;
        }
};
int main()
{

}
