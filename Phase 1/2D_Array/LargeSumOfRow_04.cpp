// Largest Sum and Index of Rows
#include <iostream>
using namespace std;

int LargestIndex(int arr[][3], int row, int col)
{
    int maxi = 0;
    int RowIndex = 0;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }

        cout << "Row Wise Sum : " << sum << endl;

        if (sum > maxi)
            maxi = sum;
        RowIndex = i; // "i" is number of row
    }
    cout << "Maximum sum : " << maxi << endl;
    return RowIndex;
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

    cout << "Largest Index is : " << LargestIndex(arr, 3, 3);

    return 0;
}