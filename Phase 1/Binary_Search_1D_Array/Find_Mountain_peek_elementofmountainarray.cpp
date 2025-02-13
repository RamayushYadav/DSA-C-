// find the peek element of mountain array
#include <iostream>
using namespace std;

int PeekOfMountain(int arr[], int size)
{
    int start = 0;    
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start < end)
    {
        if (arr[mid] < arr[mid + 1]) 
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
    int arr[] = {2, 4, 5, 1};

    cout << "The peek index element of that mountain array is " << PeekOfMountain(arr, 3) << endl;
    cout << "The peek element element of that mountain array is " << arr[PeekOfMountain(arr, 3)] << endl;
    return 0;
}