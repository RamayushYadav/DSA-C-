// // Min Heap
// 1 based indexing
// #include <iostream>
// using namespace std;

// void heapify(int arr[], int n, int i)
// {
//     int smallest = i;
//     int left = 2 * i;
//     int right = 2 * i + 1;

//     if (left <= n && arr[smallest] > arr[left])
//     {
//         smallest = left;
//     }

//     if (right <= n && arr[smallest] > arr[right])
//     {
//         smallest = right;
//     }

//     if (smallest != i)
//     {
//         swap(arr[smallest], arr[i]);
//         heapify(arr, n, smallest);
//     }
// }

// int main()
// {
//     int arr[6] = {-1, 54, 55, 50, 52, 53};
//     int n = 5;
//     for (int i = n / 2; i > 0; i--)
//     {
//         heapify(arr, n, i);
//     }

//     cout << "Print the array" << endl;
//     for (int i = 1; i <= n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }


// 0 based indexing
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;  // Fix: Use 2 * i + 1 for left child
    int right = 2 * i + 2; // Fix: Use 2 * i + 2 for right child

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 6; // Fix: Change the size of the array
    for (int i = n / 2 - 1; i >= 0; i--) // Fix: Start from n/2 - 1
    {
        heapify(arr, n, i);
    }

    cout << "Print the array" << endl;
    for (int i = 0; i < n; i++) // Fix: Change condition to i < n
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
