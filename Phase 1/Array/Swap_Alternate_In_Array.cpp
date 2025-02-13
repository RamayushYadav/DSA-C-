// Swap Alternate in array
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

void AlternateSwap(int arr[], int size)
{
    int i = 0;
    // size even ho toh
    if (size % 2 == 0)
    {
        while (i < size)
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
            i += 2;
        }
    }
    // size odd ho toh
    else
    {
        while (i < size - 1)
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
            i += 2;
        }
    }
    cout << endl;
}

// Another way of swap alternate
// void swapnum(int arr[], int size)
// {
//        for (int i = 0; i < size; i+=2)
//     {
//     if (i + 1 < size)
//         {
//             swap(arr[i], arr[i + 1]);
//         }
//     }
// }

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Before swap elememts are : " << endl;
    printArray(arr, n);
    AlternateSwap(arr, n);
    cout << "After swap elememts are : " << endl;
    printArray(arr, n);
    return 0;
}