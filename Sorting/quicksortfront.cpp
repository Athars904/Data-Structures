#include <iostream>
using namespace std;

int partition(int[], int, int);
void quickSort(int[], int, int);

int main()
{
    int size;
    cout << "ENTER Array Size: ";
    cin >> size;
    int arr[size];
    cout << "ENTER Array Data: ";
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr,0,n-1);
    cout << "Sorted Array: ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << "   ";
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = low;
    low++;
    while(1)
    {
        while(arr[low]<=arr[pivot])
            low++;
        while(arr[high]>arr[pivot])
            high--;
        if(low<high)
        {
            swap(arr[low],arr[high]);
        }
        else
        {
            swap(arr[pivot],arr[high]);
            return high;
        }
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
	{
		int pi= partition(arr, low, high);
		quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
	}
}
