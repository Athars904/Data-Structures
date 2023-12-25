#include<iostream>
using namespace std;
#define n 20
class queues
{
private:
    int *arr;
    int frontt;
    int backk;
public:
    queues()
    {
        arr=new int[n];
        frontt=-1;
        backk=-1;
    }
    void push(int x)
    {
        if (backk==n-1)
        {
            cout << "Queues Overflow..." ;
            return;
        }
        backk++;
        arr[backk]=x;
        if (frontt==-1)
        {
            frontt++;
        }
    }
    void pop()
    {
        if (frontt==-1 || frontt > backk)
        {
            cout << "QUEUE IS EMPTY...";
            return;
        }
        frontt++;
    }
    int top()
    {
        if (frontt==-1 || frontt > backk)
        {
            cout << "QUEUE IS EMPTY...";
            return -1;
        }
        return arr[frontt];
    }
};
int main()
{

}
