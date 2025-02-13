// search element
// row and column both are sorted
// 1  4  7  11
// 2  5  8  12
// 3  6  9  16
// 10 13 14 17
#include <iostream>
using namespace std;

bool searchMatrix(int matrix[][3], int row, int col, int target)
{
    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
        {
            return 1;
        }
        if (element < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
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
}