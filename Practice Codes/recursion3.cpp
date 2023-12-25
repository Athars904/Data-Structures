#include<iostream>
using namespace std;
int fibocanni(int x)
{
    if(x<=1)
    {
        return x;
    }
    return fibocanni(x-1)+fibocanni(x-2);

}
int main()
{
    int x;
    cout << "Enter the number of terms: ";
    cin >> x;
    for (int i=0;i<x;i++)
    {
        cout << fibocanni(i) << " ";
    }
}