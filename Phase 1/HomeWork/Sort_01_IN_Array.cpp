// sort 0 and 1 in an array 0 is in left 1 is in right


// sort 0 , 1 and 2 HOMEWORK ******************************************************************************

#include <iostream>
using namespace std;

void printArraY(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        while (arr[left] == 0 && left < right)
        {
            left++;
        }
        while (arr[right] == 1 && left < right)
        {
            right--;
        }
        // arr[left] == 1 and arr[right] == 0
        if (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[7] = {0, 1, 0, 0, 1, 0, 1};

    printArraY(arr, 7);
    sort(arr, 7);
    printArraY(arr, 7);

    return 0;
}