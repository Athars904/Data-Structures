#include<iostream>
using namespace std;
int y;
int abs(int ab)
{
    if (ab<0)
    {
        int num;
        num=-ab;
        return num;
    }
    else
        return ab;
}
int main()
{
    int x;
    cout << "Enter the number : ";
    cin >> x;
    cout << "The absolute value of number is : " << abs(x);
}
