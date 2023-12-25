#include<iostream>
#include<cstdlib>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void printLinkedList(Node *ptr)
{
    while (ptr!=NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr=ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *sec;
    struct Node *trd;
    head=(struct Node *)malloc(sizeof(struct Node));
    sec=(struct Node *)malloc(sizeof(struct Node));
    trd=(struct Node *)malloc(sizeof(struct Node));
    head->data=22;
    head->next=sec;
    sec->data=34;
    sec->next=trd;
    trd->data=43;
    trd->next=NULL;
    printLinkedList(head);

}
