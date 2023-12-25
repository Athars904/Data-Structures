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
        Node (int d)
        {
            data=d;
            next=NULL;
        }
    };
    Node *frontt;
    Node *backk;
    public:
        Queues ()
        {
            frontt=NULL;
            backk=NULL;
        }
        void push(int val)
        {
            Node *temp=new Node(val);
            if (frontt==NULL)
            {
                backk=temp;
                frontt=temp;
                return;
            }
            backk->next=temp;
            backk=temp;
        }
        void pop()
        {
            if (frontt==NULL)
            {
                cout << "Queue Underflow..";
                return;
            }
            Node *temp=frontt;
            frontt=frontt->next;
            delete temp;
        }
        int top()
        {
            if (frontt==NULL)
            {
                cout << "NO VALUE IN QUEUE..";
                return -1;
            }
            return frontt->data;
        }
        void deletePosition(int pos) {
            if (frontt==NULL) {
                cout << "Queue is empty" << endl;
                return;
            }
            if (pos == 1) {
                pop();
                return;
            }
            Node* current = frontt;
            Node* previous = NULL;
            for (int i = 1; i < pos && current != NULL; i++) {
                previous = current;
                current = current->next;
            }
            if (current == NULL) {
                cout << "Invalid position" << endl;
                return;
            }
            previous->next = current->next;
            delete current;
        }
};
int main()
{
    Queues q1;
    q1.push(54);
    q1.push(37);
    q1.push(34);
    q1.deletePosition(1);
    cout << q1.top() << endl;
    q1.pop();
    cout <<q1.top();
}

