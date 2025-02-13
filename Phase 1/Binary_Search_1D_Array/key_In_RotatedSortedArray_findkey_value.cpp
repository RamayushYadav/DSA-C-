// find key value in rotated sorted array
#include <iostream>
using namespace std;

int pivotvalue(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int BinarySearch(int arr[], int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int keyvalue(int arr[], int size, int Key)
{
    int pivot = pivotvalue(arr, size);
    // Binary Search on second line
    if (Key >= arr[pivot] && Key <= arr[size - 1])
    {
        return BinarySearch(arr, pivot, size - 1, Key);
    }
    // Binary Search on first line
    else
    {
        return BinarySearch(arr, 0, pivot - 1, Key);
    }
}

int main()
{
    int arr[] = {7, 9, 1, 2, 3};

    cout << "The key index in rotated sorted array is " << keyvalue(arr, 5, 2) << endl;
    cout << "The key value in rotated sorted array is " << arr[keyvalue(arr, 5, 2)] << endl;
    return 0;
}