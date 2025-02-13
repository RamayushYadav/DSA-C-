// Find array is sorted or not
#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    // base case
    if (size == 0 || size == 1)
        return true;

    // processing
    if (arr[0] > arr[1])
        return false;

    else
    {
        // recursive relation
        int remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}

int main()
{
    int arr[] = {2, 3, 5, 7, 8, 10};

    // Recursive function call
    int ans = isSorted(arr, 6);

    if (ans)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array is not sorted";
    }

    return 0;
}