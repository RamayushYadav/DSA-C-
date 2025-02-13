// search element are found or not found
// 1 2 3
// 4 5 6 
// 7 8 9

#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][3], int row, int col, int target)
{
    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = matrix[mid / col][mid % col];
        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return 0;
}

int main()
{
    int arr[3][3];
    cout << "Enter the elements in 2D array : ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int searchElement;
    cout << "Enter the seraching element : ";
    cin >> searchElement;

    if (searchMatrix(arr, 3, 3, searchElement))
    {
        cout << "FOUND";
    }
    else
    {
        cout << "NOT FOUND";
    }

    return 0; 
}