// // Selection Sort
#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
        // int temp = arr[minIndex];
        // arr[minIndex] = arr[i];
        // arr[i] = temp;
    }
    cout << endl;
}

//     // sort(arr.begin(), arr.end());
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }

int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements in array : "; 
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, size);
    SelectionSort(arr, size);
    printArray(arr, size);
    return 0;
}
