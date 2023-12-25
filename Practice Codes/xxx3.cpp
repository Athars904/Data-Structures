    #include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node * prev;
   node()
   {
    next=nullptr;
    data=0;
    prev=nullptr;
   }
};
 void display(node *head,node * tail)
    { int i=0;
        node *current=head;
        while(current!=nullptr && i<10)
        {
            cout << current->data << " -> ";
            current=current->next;
            i++;
        }
        cout << "nullptr" << endl;
         cout << "back nullptr";
         node * c= tail;

/*while(c!=nullptr)
        {
            cout << " -> " << c->data ;
            c=c->prev;
        }
        cout << endl; */
    }
/*void deletenode(node*&head,int index)
{
    if(head==nullptr)
    return ;
    node * current= head;
    if (index==0)
    {

        head=head->next;
        delete current;
        return ;
    }
    int counter=0;
    while(counter!=index-1&&current->next!=nullptr)
    {
            current=current->next;
            counter++;
    }
    if(counter==index-1 && current->next!=nullptr){
    node *temp=current->next;
    current->next=temp->next;
    delete temp;
    return;
    }

}
void replacenode(node*&head,int index,int data)
{
 if(head==nullptr)
 return ;
 if(index==0)
 {
    head->data=data;
    return;
 }
 node * current=head;
 int counter=0;
 while (counter!=index&& current->next!=nullptr )
 {
    current=current->next;
    counter++;
 }
 if(counter==index&& current->next!=nullptr)
 {
    current->data=data;
    return;
 }

}
void insertnode(node * &head,int index,int data)
{
    if(head==nullptr)
    {
        return;
    }
    node *current=head;
    node * newnode=new node;
    newnode->next=nullptr;
    newnode->data=data;
    if (index==0)
    {
        newnode->next=current;
        head=newnode;
            return;
    }
    int counter=0;
    while(counter!=index-1 && current->next!=nullptr)
    {
        current=current->next;
        counter++;
    }
    if(counter==index-1&& current->next!=nullptr)
    {
        newnode->next=current->next;
        current->next=newnode;
        newnode->prev=current;
        return;
    }
    if(current->next==nullptr)
    {

        current->next=newnode;
        newnode->prev=current;
        return;
    }

}*/
main()
{
   node * head=nullptr;
   node *tail=nullptr;
   int number=4;
   for(int i=0;i<number;i++)
   {
    int data;
    cout << "enter data: ";
    cin >> data;
    node * newnode=new node;
    newnode->data=data;
    //newnode->next=nullptr;

    if(head==nullptr)
    {
        head=newnode;

    }
    else
    {
        node * current=head;
        while(current->next!=nullptr)
        {
            current=current->next;
        }
        current->next=newnode;
        newnode->prev=current;
           tail=newnode;

    }

   }
    tail->next=head;
   display(head,tail);
   //replacenode(head,2,100);
   //display(head);
   //deletenode(head,2);
  //display(head);
  // insertnode(head,2,69);
  // display(head);
}

