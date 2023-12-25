#include<iostream>
using namespace std;
void AddElement(int arr[], int& size, int position, int element) {
    for (int i = size; i > position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = element;
    size++;
}
void DeleteElement(int arr[], int& size, int position)
{
    for(int i=position;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
}
void ModifyElement(int arr[],int& size, int position, int newV)
{
    arr[position]=newV;
}
void DisplayData(int arr[],int& sizer)
{
    for (int i=0;i<sizer;i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int size;
    int element;
    int pos;
    cout << "Enter the size of Array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the numbers in array: ";
    for (int i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    bool quit=false;
    int select;
    cout << "Press 1 to Add, 2 to delete, 3 to Modify, 4 to Display, 5 to quit: ";
    cin >> select;
    switch(select)
    {
    case 1:
        cout << "Enter the Element number you want to be add: ";
        cin >> element;
        cout << "At which position do you want this to be added? : ";
        cin >> pos;
        AddElement(arr,size, pos,element);
        DisplayData(arr,size);
        break;
    case 2:
        cout << "At which Index do you want element to be deleted ";
        cin >> pos;
        DeleteElement(arr,size,pos);
        DisplayData(arr,size);
        break;
    case 3:
        cout << "Enter the index of element you want to modify: ";
        cin >> pos;
        int newvalue;
        cout << "Enter the new Value: ";
        cin >> newvalue;
        ModifyElement(arr,size,pos,newvalue);
        DisplayData(arr,size);
        break;
    case 4:
        cout << "Displaying....";
        break;
    case 5:
        cout << "quiting.....";
        quit=true;
        break;
    default:
        cout << "Please use 1,2,3,4,5.";
    }
}
