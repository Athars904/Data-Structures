#include<iostream>
using namespace std;
int main()
{
    int arr1[3][3];
    int i,j;
    cout << "Enter the elements of Array 1: ";
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            cin >> arr1[i][j];
        }
    }
    int arr2[3][3];
    cout << "Enter the Elements of Array 2: ";
        for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            cin >> arr2[i][j];
        }
    }
    cout << "The sum of two 2D Arrays is: " << endl;
    int arr3[3][3];
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            arr3[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    cout << "Displaying the sum of 2 Two Dim Arrays: " << endl;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            cout<<arr3[i][j]<<" ";
        cout<<endl;
}
}
