// Linear Search in Array
#include <iostream>
using namespace std;

bool search(int arr[], int key)
{
    for (int i = 0; i < 10; i++)
    {
        if (key == arr[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[10] = {32, 4, 67, 3, 6, 3, 8, 1, -8, 90};
    int key;
    cout << "Enter the key value : ";
    cin >> key;
    bool found = search(arr, 5);
    if (found)
    {
        cout << "Element are present in array";
    }
    else
    {
        cout << "Element are not present in array";
    }
    return 0;
}