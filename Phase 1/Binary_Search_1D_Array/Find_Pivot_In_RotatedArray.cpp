// Find pivot in rotated array

#include <iostream>
using namespace std;

int pivotElement(int arr[], int size)
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

int main()
{
    int arr[] = {3, 6, 8, 17, 20, 1};

    cout << "The pivot index is : " << pivotElement(arr, 6) << endl;
    cout << "The pivot element is : " << arr[pivotElement(arr, 6)] << endl;

    return 0;
}