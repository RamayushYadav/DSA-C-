// Deletion in Array
#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void delteionAtIndex(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[10] = {7, 4, 5, 2, 1};
    int size = 5, index = 1;

    display(arr, size);
    delteionAtIndex(arr, size, index);
    // The most important line number 21
    size -= 1;
    display(arr, size);

    return 0;
}