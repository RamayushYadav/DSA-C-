// find the first and last occurence of an array arr[]={2,1,3,3,3,3,5};
// first = 2
// last = 5
#include <iostream>
using namespace std;

int firstOccerance(int arr[], int size, int key)
{
    int start = 0;
    int ans;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        else if (key < arr[mid])
        { // left me jao
            end = mid - 1;
        }
        else if (key > arr[mid])
        { // right me jao
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccerance(int arr[], int size, int key)
{
    int start = 0;
    int ans;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }

        else if (key < arr[mid])
        { // left me jao
            end = mid - 1;
        }
        else if (key > arr[mid])
        { // right me jao
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    int even[] = {1, 2, 3, 3, 3, 3, 5};
    cout << "The left most index of the number 3 is " << firstOccerance(even, 7, 3) << endl;
    cout << "The right most index of the number 3 is " << lastOccerance(even, 7, 3);
    return 0;
}