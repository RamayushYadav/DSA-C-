#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int length1 = mid - s + 1;
    int length2 = e - mid;

    int *first = new int[length1];
    int *second = new int[length2];

    // copy values
    int mainArrayIndex = s;
    for (int i = 0; i < length1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < length2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge two sorted array
    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;

    while (index1 < length1 && index2 < length2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // remaining elements of first or second array in main array
    while (index1 < length1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < length2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // left part sort karna hai
    mergeSort(arr, s, mid);

    // right part sort karna hai
    mergeSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

int main()
{
    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;

    mergeSort(arr, 0, n - 1);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// Certainly! Let's dry run (step-by-step execution) the provided C++ code to sort the array using the Merge Sort algorithm.

// Given array: {2, 5, 1, 6, 9}

//-> Initial State:
// mergeSort function is called initially with parameters s = 0 (start index) and e = n - 1 = 4 (end index) for the array {2, 5, 1, 6, 9}.

// mergeSort Function Calls:

//1) Initial Call: mergeSort(arr, 0, 4)

// Calculates mid = 0 + (4 - 0) / 2 = 2.
// Calls mergeSort(arr, 0, 2) for the left half and mergeSort(arr, 3, 4) for the right half.

//2) Left Half: mergeSort(arr, 0, 2)

// Calculates mid = 0 + (2 - 0) / 2 = 1.
// Calls mergeSort(arr, 0, 1) for the left sub-array and mergeSort(arr, 2, 2) for the right sub-array.

//3) Left Sub-array: mergeSort(arr, 0, 1)

// Since s = 0 and e = 1, it's a sub-array with two elements {2, 5}. No sorting needed as it's already sorted.

//4) Right Sub-array: mergeSort(arr, 2, 2)
// Sub-array with a single element {1}. No sorting needed as it's already sorted.

//5) Merging the Left and Right Sub-arrays in the Left Half: merge(arr, 0, 1, 2)
// Merging the sub-arrays {2, 5} and {1} to form a sorted sub-array {1, 2, 5}.

//6) Right Half: mergeSort(arr, 3, 4)
// Sub-array {6, 9}. No sorting needed as it's already sorted.

//7) Merging the Left and Right Halves: merge(arr, 0, 2, 4)
// Merging sorted sub-arrays {1, 2, 5} and {6, 9} to form the final sorted array {1, 2, 5, 6, 9}.


// --> Final Sorted Array: {1, 2, 5, 6, 9}
// The program executes the Merge Sort algorithm recursively by dividing the array into smaller parts
//  and then merges them in a sorted order, resulting in the sorted array {1, 2, 5, 6, 9}.
