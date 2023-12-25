#include <iostream>
using namespace std;
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size-1;i++)
    {
        int j=i;
        while (j>0 && arr[j-1]<arr[j])
        {
            swap(arr[j],arr[j-1]);
            j=j-1;
        }
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    insertionSort(arr, size);

    std::cout << "\nSorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
