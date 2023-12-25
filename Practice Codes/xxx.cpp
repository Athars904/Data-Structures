#include<iostream>
using namespace std;
class stack
{
    int *arr;
    int capacity;
    int nextindex;
public:
    stack()
    {
        nextindex=0;
        capacity=4;
        arr=new int[capacity];
    }
    stack (int ele)
    {
        nextindex=0;
        capacity=ele;
        arr=new int[capacity];
    }
    void push(int ele)
    {
        arr[nextindex]=ele;
        nextindex++;

    }
    void pop(){

    nextindex--;
    }
    int top()
    {
        return arr[nextindex-1];
    }
      int size()
        {
            return nextindex;
        }
};
int prefix(string n)
{
     stack st;
     for(int i=n.size()-1;i>=0;i--)
     {
         if(isdigit(n[i]))
         {
             st.push(n[i]-'0');
         }
         else
         {
             int op1=st.top();
             st.pop();
             int op2=st.top();
             st.pop();
             if (n[i] == '+') {
                st.push(op1 + op2);
            }
            else if (n[i] == '-') {
                st.push(op1 - op2);
            }
            else if (n[i] == '*') {
                st.push(op1 * op2);
            }
            else if (n[i] == '/') {
                st.push(op1 / op2);
         }
     }
}
return st.top();
}
int post(string n)
{
     stack st;
     for(int i=0;i<=n.size()-1;i++)
     {
         if(isdigit(n[i]))
         { cout << "n[i]" << n[i] << endl;
             st.push(n[i]-'0');
         }
         else
         {
             int op1=st.top();
             st.pop();
             int op2=st.top();
             st.pop();
             if (n[i] == '+') {
                st.push(op1 + op2);
            }
            else if (n[i] == '-') {
                st.push(op1 - op2);
            }
            else if (n[i] == '*') {
                st.push(op1 * op2);
            }
            else if (n[i] == '/') {
                st.push(op1 / op2);
         }
     }
}
return st.top();
}

main()
{
    stack s;
   string n="5555-*+";
   string n1="+*-5565";
 cout <<  prefix(n1) << "   " << post(n) ;
}

