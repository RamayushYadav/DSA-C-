// Spiral print
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> spiralOrder(vector<vector<int>> &matrix)
// {
//     vector<int> ans;
//     int row = matrix.size();
//     int col = matrix[0].size();

//     int count = 0;
//     int total = row * col;

//     // index initialisation
//     int startingRow = 0;
//     int startingCol = 0;
//     int endingRow = row - 1;
//     int endingCol = col - 1;

//     while (count < total)
//     {
//         // print starting row
//         for (int index = startingCol; count < total && index <= endingCol; index++)
//         {
//             ans.push_back(matrix[startingRow][index]);
//             count++;
//         }
//         startingRow++;
//         // print ending column
//         for (int index = startingRow; count < total && index <= endingRow; index++)
//         {
//             ans.push_back(matrix[index][endingCol]);
//             count++;
//         }
//         endingCol--;
//         // print ending row
//         for (int index = endingCol; count < total && index >= startingCol; index--)
//         {
//             ans.push_back(matrix[endingRow][index]);
//             count++;
//         }
//         endingRow--;
//         // print starting col
//         for (int index = endingRow; count < total && index >= startingRow; index--)
//         {
//             ans.push_back(matrix[index][startingCol]);
//             count++;
//         }
//         startingCol++;
//     }
//     return ans;
// }

// int main()
// {
//     int value;
//     vector<vector<int>> V;
//     cout << "Enter the elements :  ";
//     for (int i = 0; i < V.size(); i++)
//     {
//         for (int j = 0; j < V[i].size(); j++)
//         {
//             cin >> value;
//             V[i].push_back(value);
//         }
//     }
//     for (int i = 0; i < V.size(); i++)
//     {
//         for (int j = 0; j < V[i].size(); j++)
//         {
//             cout << V[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

void spiralOrder(int arr[][3], int row, int col)
{
    int count = 0;
    int total = row * col;

    // Initialize index
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total)
    {

        // starting Row
        for (int index = startingCol; (count < total) && (index <= endingCol); index++)
        {
            cout << arr[startingRow][index] << " ";
            count++;
        }
        startingRow++;

        for (int index = startingRow; (count < total) && (index <= endingRow); index++)
        {
            cout << arr[index][endingCol] << " ";
            count++;
        }
        endingCol--;

        for (int index = endingCol; (count < total) && (index >= startingCol); index--)
        {
            cout << arr[endingRow][index] << " ";
            count++;
        }
        endingRow--;

        for (int index = endingRow; (count < total) && (index >= startingRow); index--)
        {
            cout << arr[index][startingCol] << " ";
            count++;
        }
        startingCol++;
    }
}

int main()
{
    int arr[3][3];
    cout << "Enter the elements :  ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    spiralOrder(arr, 3, 3);

    return 0;
}