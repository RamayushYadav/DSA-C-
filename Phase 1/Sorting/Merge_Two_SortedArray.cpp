// Merge two sorted array
#include <iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else if (arr2[j] < arr1[i])
        {
            arr3[k++] = arr2[j++];
        }
    }
    // copy first array remaining element in third array
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }
    // copy second array remaining element in third array
    while (j < m)
    {
        arr3[k++] = arr1[i++];
    }
}

void print(int ans[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[3] = {2, 4, 6};
    int arr3[8] = {0};
    merge(arr1, 5, arr2, 3, arr3);
    print(arr3, 8);
    return 0;
}