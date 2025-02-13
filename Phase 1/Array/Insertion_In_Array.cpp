// insertion in array
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

int insertionInArray(int arr[], int size, int capacity, int element, int index)
{
    // container is full
    while (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;

    return 1;
}

int main()
{
    int arr[10] = {2, 5, 3, 1};
    int size = 4, capacity = 10, index = 3;
    int element = 49;

    display(arr, size);
    insertionInArray(arr, size, capacity, element, index);
   // The most important line number 40
    size += 1;
    display(arr, size);

    return 0;
}