// Row wise sum
#include <iostream>
using namespace std;

void RowWiseSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "Row sum = " << sum << endl;
    }
}

void ColumnWiseSum(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[j][i];
        }
        cout << "Column sum = " << sum << endl;
    }
}

int main()
{
    int arr[3][3];

    cout << "Enter the elements in array : ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    RowWiseSum(arr, 3, 3);
    ColumnWiseSum(arr, 3, 3);

    return 0;
}