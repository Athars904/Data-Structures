#include<iostream>
using namespace std;
class Stack
{
    int *arr;
    int NextIndex;
    int capacity;
    public:
    Stack()
    {
        capacity=4;
        arr=new int[capacity];
        NextIndex=0;
    }
    Stack(int cap)
    {
        capacity=cap;
        arr=new int[capacity];
        NextIndex=0;
    }
    int size()
    {
        return NextIndex;
    }
    bool isEmpty()
    {
        return NextIndex==0;
    }
    void push(int ele)
    {
        if(NextIndex==capacity)
        {
            capacity++;
            int *arr1=new int[capacity];
            for (int i=0;i<capacity;i++)
            {
                arr1[i]=arr[i];
            }
            arr1[NextIndex]=ele;
            NextIndex++;
        }
        else
        {
            arr[NextIndex]=ele;
            NextIndex++;
        }}
    void pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty..." ;
            return;
        }
        NextIndex--;
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty....";
            return 0;
        }
        return arr[NextIndex-1];
    }

};
    int evaluatePreFix(string exp)
    {
        Stack s;
        for (int i=exp.size();i>=0;i--)
        {
            if (isdigit(exp[i]))
            {
                int num=exp[i]-'0';
                s.push(num);
            }
            else
            {
                int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            if (exp[i] == '+')
                s.push(op1 + op2);
            else if (exp[i] == '-')
                s.push(op1 - op2);
            else if (exp[i] == '*')
                s.push(op1 * op2);
            else if (exp[i] == '/')
                s.push(op1 / op2);
            }
        }
        return s.top();

    }
int main()
{
    string s1="- + 1 * 3 / 6 2 4 5" ;
    int result =evaluatePreFix(s1);
    cout << "Result = " << result ;
    return 0;
    }
