#include<iostream>
using namespace std;
class Stack
{
    private:
    int *arr;
    int nextIndex;
    int capacity;
    public:
    Stack()
    {
        capacity=4;
        arr=new int[capacity];
        nextIndex=0;
    }
    Stack(int cap)
    {
        capacity=cap;
        arr=new int[capacity];
        nextIndex = 0;
    }
    int size()
    {
        return nextIndex;
    }
    void push(int element){

        if (nextIndex==capacity)
        {
            cout << "Stack is Full";
            return;
        }

    else
    {
        arr[nextIndex]=element;
        nextIndex++;
    }
    }
    int top()
    {
        return arr[nextIndex];
    }

};
int main()
{

}
