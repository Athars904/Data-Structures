#include<iostream>
using namespace std;
int sumElements(int arr[],int s)
{
    if (s==0)
    {
        return 0;
    }
    int sm=sumElements(arr+1,s-1);
    int a=arr[0]+sm;
    return a;
}
int main()
{
    int siz;
    cout << "Enter the size of Array: ";
    cin >> siz;
    int arr[siz];
    cout << "Enter the Elements of Array: ";
    for (int i=0;i<siz;i++)
    {
        cin >> arr[i];
    }
    cout <<sumElements(arr,siz);
}
