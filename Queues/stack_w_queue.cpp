#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1,q2;
public:
    void push(int data)
    {
        q1.push(data);
    }
    void pop()
    {
        while(q1.size()>1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        q1 = q2;
    }
    int top()
    {
        int x;
        while(!q1.empty())
        {
            if(q1.size()==1)
            {
                x = q1.front();
            }
            q2.push(q1.front());
            q1.pop();
        }
        q1 = q2;
        return x;
    }
};

int main()
{
    Stack s;
    int data;
    cout<<"Enter data (-1) to stop:)";
    cin>>data;
    while(data!=-1){
        s.push(data);
        cin>>data;
    }
    cout << s.top();
    s.pop();
    cout << s.top();
    s.pop();
    cout << s.top();
    s.pop();
}
