// Card Game is the best of insertion sort 
#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Using for loop
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // Shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // Ruk jao
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

// Using while loop
void insertionsort(int arr[], int n)
{
    int i = 1;
    while (i < n)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            { // Shift
                arr[j + 1] = arr[j];
            }
            else
            { // Ruk jao
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
        i++;
    }
}

int main()
{
    int arr[] = {2, 4, 1, 5, 3};
    printArray(arr, 5);
    // Using for loop
    // InsertionSort(arr, 5);

    // Using while loop
    insertionsort(arr, 5);
    printArray(arr, 5);

    return 0;
}