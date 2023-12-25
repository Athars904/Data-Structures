#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;
public:
    void push(int data)
    {
        s1.push(data);
        return;
    }
    void pop()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int t = s1.top();
                s2.push(t);
                s1.pop();
            }
        }
        return s2.pop();

    }
    int first()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int t = s1.top();
                s2.push(t);
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    cout << q.first();
    q.pop();
    cout << q.first();
    q.pop();
    cout << q.first();
    q.pop();
    q.push(69);
    cout << q.first();
    q.pop();
    cout << q.first();
    q.pop();
    cout << q.first();

}
