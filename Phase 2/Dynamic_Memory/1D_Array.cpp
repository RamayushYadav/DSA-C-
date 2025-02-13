#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    // Dynamic array created
    int *arr = new int[n];
    cout << "Enter the elements in array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Delete memory from heap
    delete[] arr;

    return 0;
}