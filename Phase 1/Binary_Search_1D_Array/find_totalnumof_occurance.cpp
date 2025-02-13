// Find the total number of occurence
#include <iostream>
using namespace std;

int leftmostoccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
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
    return ans;
}

int rightmostoccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int ans;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
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
    return ans;
}

int main()
{
    int even[] = {1, 2, 3, 3, 3, 3, 5};

    cout << "The left most occurence of 3 at index " << leftmostoccurence(even, 7, 3) << endl;
    cout << "The right most occurence of 3 at index " << rightmostoccurence(even, 7, 3) << endl;

    int total = rightmostoccurence(even, 7, 3) - leftmostoccurence(even, 7, 3) + 1;
    cout << "The total number of occurence of number 3 is " << total << endl;
    return 0;
}