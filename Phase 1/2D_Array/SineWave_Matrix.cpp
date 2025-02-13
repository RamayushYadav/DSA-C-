#include <iostream>
using namespace std;

void printSineWave(int arr[][3], int nrows, int mcols)
{
    for (int col = 0; col < mcols; col++)
    {
        if (col % 2 == 0)
        {
            for (int row = 0; row < nrows; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            for (int row = nrows - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main()
{
    int arr[3][3];
    cout << "Enter the elements : ";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    printSineWave(arr, 3, 3);

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> printSineWave(vector<vector<int>> arr, int nrows, int mcols)
// {
//     vector<int> ans;
//     for (int col = 0; col < mcols; col++)
//     {
//         if (col % 2 == 0)
//         {
//             for (int row = 0; row < nrows; row++)
//             {
//                 ans.push_back(arr[row][col]);
//              }
//         }
//         else
//         {
//             for (int row = nrows - 1; row >= 0; row--)
//             {
//                 ans.push_back(arr[row][col]);
//             }
//         }
//     }
//     return ans;
// }

// int main()
// {   int value;
//     vector<vector<int>> V;
//     cout << "Enter the elements : ";

//     for (int i = 0; i < V.size(); i++)
//     {
//         for (int j = 0; j < V[i].size(); j++)
//         {
//              cin>> value;
//              V[i].push_back(value);
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

//     printSineWave(V, 3, 3);

//     return 0;
// }
