#include <iostream>
using namespace std;

void print(int arr[], int s, int e)
{

    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;
}

bool binarySearch(int arr[], int start, int end, int key)
{
    // print function
    print(arr, start, end);

    // base case
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    cout << "Mid index is -> " << mid << endl
         << endl;

    // if mid is equal to key
    if (arr[mid] == key)
        return true;

    // jab element smaller than mid
    if (key < arr[mid])
    {
        // end = mid - 1;
        return binarySearch(arr, start, mid - 1, key);
    }
    // jab element smaller than mid
    else
    {
        // start = mid + 1;
        return binarySearch(arr, mid + 1, end, key);
    }
}


int main()
{
    int arr[] = {2, 4, 5, 8, 9, 12};
    // int arr[] = {1, 2, 4, 6, 8, 10};
    int size = 6;
    int key = 9;
    // int key = 1;
    cout << "Present or not" << endl
         << endl;
    int ans = binarySearch(arr, 0, size - 1, key);
    if (ans)
    { 
        cout << "Element is Present";
    }
    else
    {
        cout << "Element is not Present";
    }
    return 0;
}