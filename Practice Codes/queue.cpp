#include<iostream>
using namespace std;
class Queue
{
    private:
    int *arr;
    int front;
    int back;
    public:
    Queue(int x)
    {
        arr=new int[x];
        front=-1;
        back=-1;
    }
    Queue()
    {
        front=-1;
        back=-1;
    }
    bool isEmpty()
    {
        if(front==-1||front>back)
        {
            return true;
        }
        return false;
    }
    void push (int ele)
    {
        if (back==ele-1)
        {
            cout << "Overflow.." << endl;
            return;
        }
        back++;
        arr[back]=ele;
        if (front==-1)
        {
            front++;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "NO ELEMENT IN QUEUE...";
            return;
        }
        front++;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "NO ELEMENTS IN QUEUE...";
            return 0;
        }
        return arr[front];
    }
};
int main()
{
    Queue q;
    q.push(15);
    q.push(12);
    q.push(23);
    q.push(34);
    cout << q.top();
    q.pop();
    cout << q.top();
}
