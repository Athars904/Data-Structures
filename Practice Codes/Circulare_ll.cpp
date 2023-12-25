#include<iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;
public:
    Node(int val)
    {
        data=val;
        next=NULL;
    }
    void insertatHead(Node &head, int val)
    {
        Node *n=new Node(val);
        Node* temp=head;
        while (temp->head!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;
        head=n;
    }
    void insertatTail(Node &head,int val)
    {
        if (head==NULL)
        {
            insertathead(head,val);
            return;
        }
        Node *n=new node(val);
        Node *temp=head;
        while (temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;
    }
    void deleteHead(Node* &head)
    {
        Node*temp=next;
        while (head!=NULL)
        {
            temp=temp->next;
        }
        Node *todelete=head;
        temp->next=head->next;
        head=head->next;
        delete todelete;
    }
    void deletion(Node *head,int pos)
    {
        if (pos ==1)
        {
            deleteHead(head)
        }
        Node *temp=head;
        int counter=1;
        while (counter != pos-1)
        {
            temp=temp->next;
            counter++;
        }
        Node *todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
};
int main()
{

}
