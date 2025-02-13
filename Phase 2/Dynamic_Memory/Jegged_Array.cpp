// 1 2 3 4
// 5 6
// 7 8 9
#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter the row : ";
    cin >> row;
    
    // dynamically row created
    int **arr = new int *[row];
    int size[] = {4, 2, 3};

    // dynamically column created
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[size[i]];
    }

    cout << "Enter the elements for jegged array : ";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}
