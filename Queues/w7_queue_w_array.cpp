#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int firstIndex,nextIndex,capacity,size;
public:
    Queue(int capacity = 5)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        firstIndex = 0;
        nextIndex = 0;
        size = 0;
    }
    void push(int data)
    {
        if(size == capacity)
        {
            cout << "Queue Full!\n";
            return;
        }
        arr[nextIndex] = data;
        nextIndex = (nextIndex+1)%capacity;
        size++;
        return;
    }
    void pop()
    {
        if(size == 0)
        {
            cout << "Queue Empty!\n";
            return;
        }
        firstIndex = (firstIndex+1)%capacity;
        size--;
        return;
    }
    void first()
    {
        if(size == 0)
        {
            cout << "Queue Empty!\n";
            return;
        }
        cout << arr[firstIndex] << endl;
        return;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    Queue x;

    x.first();
    x.push(10);
    x.push(20);
    x.push(30);
    cout << x.getSize() << endl;
    x.push(40);
    x.push(50);
    x.push(60);
    x.pop();
    x.first();
    x.push(65);
    x.pop();
    x.pop();
    x.pop();
    x.pop();
    x.first();
    x.pop();
    x.first();
    x.push(96);
    x.first();

    return 0;
}
