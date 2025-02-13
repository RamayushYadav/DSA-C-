#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    cout << "Size of array is -> " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool linearSearch(int arr[], int size, int key)
{
    // print function call
    print(arr, size);

    // base case
    if (size == 0)
        return false;

    if (arr[0] == key)
        return true;

    else
    {
        bool search = linearSearch(arr + 1, size - 1, key);
        return search;
    }
}

int main()
{
    int arr[] = {2, 1, 4, 6, 3};
    int size = 5;
    int key = 8;

    int answer = linearSearch(arr, size, key);

    if (answer)
    {
        cout << "Element is Present";
    }
    else
    {
        cout << "Element is not Present";
    }

    return 0;
}