#include<iostream>
#include<queue>
#include<stdexcept>
using namespace std;
class Stacks
{
    queue <int> q1,q2;
    int sizeofstack;
public:
        Stacks()
        {
            sizeofstack=0;
        }
    void push(int value) {
        q2.push(value);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        sizeofstack++;
    }
        void pop() {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        q1.pop();
        sizeofstack--;
    }
        int top() const {
        if (empty()) {
            throw out_of_range("Stack is empty");
        }
        return q1.front();
    }
};
int main()
{

}
