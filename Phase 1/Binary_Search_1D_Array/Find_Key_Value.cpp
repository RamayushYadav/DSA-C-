#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    // mid = (start+end)/2

    // this second formula of mid used for arrange the integer in range(pow(2,31)-1);
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        // mid value
        if (arr[mid] == key)
        {
            return mid;
        }

        // right sorted array
        if (key > arr[mid])
        {
            start = mid + 1;
        }

        // left sorted array
        // if (key < arr[mid])
        else
        {
            end = mid - 1;
        }
        // update the mid value according to start or end values
        mid = start + (end - start) / 2;
    }
    // if key value is not in the array
    return -1;
}

int main()
{
    int even[] = {2, 4, 6, 8, 10, 12, 14};
    int odd[] = {3, 5, 9, 11, 13, 15, 17};

    cout << "The number 10 is in index no." << BinarySearch(even, 7, 10) << endl;
    return 0;
}