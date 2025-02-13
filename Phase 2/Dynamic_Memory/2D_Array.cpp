#include <iostream>
using namespace std;

int main()
{
    int row, col;
    cout << "Enter the row : ";
    cin >> row;
    cout << "Enter the column : ";g
    cin >> col;

    // 2D array row dynamically created
    int **arr = new int *[row];

    // 2D array column dynamically created
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    // Taking input
    cout << "Enter the elements of matrix : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Display Output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing heap memory of row
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    // releasing heap memory of column
    delete[] arr;

    return 0;
}