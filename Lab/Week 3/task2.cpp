#include<iostream>
using namespace std;
int sortedArray(int arr[],int s)
{
    if (s==1)
    {
        return 1;
    }
    if (arr[s-1]<arr[s-2])
    {
        return 0;
    }
    return sortedArray(arr,s-1);
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
    if (sortedArray(arr,siz))
    {
        cout << "The Array is Sorted......";
    }
    else
        cout << "The Array is not Sorted.....";
}
