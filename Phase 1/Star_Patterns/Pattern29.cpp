//      *
//     ***
//    *****
//   *******
//  *********
//  *********
//   *******
//    *****
//     ***
//      *

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number n : ";
    cin >> n;
    // (m = n + 1)
    int m;
    cout << "Enter the number m : ";
    cin >> m;

    // For upper pyramid
    int row = 1;
    while (row <= n)
    {
        // For Space
        int space = n - row;
        while (space)
        {
            cout << "  ";
            space = space - 1;
        }

        // For First Triangle
        int col = 1;
        while (col <= row)
        {
            cout << "* ";
            col = col + 1;
        }

        // For Second Triangle
        int value = row - 1;
        while (value)
        {
            cout << "* ";
            value = value - 1;
        }
        cout << endl;
        row = row + 1;
    }


    // For Lower Pyramid
    int Row = 1;
    while (Row <= m)
    {

        // For space
        int Space = Row - 1;
        while (Space)
        {
            cout << "  ";
            Space = Space - 1;
        }

        // For first Triangle
        int Value = m - Row + 1;
        while (Value)
        {
            cout << "* ";
            Value = Value - 1;
        }

        // For second Triangle
        int Col = m - Row;
        while (Col)
        {
            cout << "* ";
            Col = Col - 1;
        }
        cout << endl;
        Row = Row + 1;
    }

    return 0;
}

// Another perfect pattern solution

//      *
//     ***
//    *****
//   *******
//  *********
//   *******
//    *****
//     ***
//      *

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the number n : ";
//     cin >> n;
    
//     // For upper pyramid
//     int row = 1;
//     while (row <= n)
//     {
//         // For Space
//         int space = n - row;
//         while (space)
//         {
//             cout << "  ";
//             space = space - 1;
//         }

//         // For First Triangle
//         int col = 1;
//         while (col <= row)
//         {
//             cout << "* ";
//             col = col + 1;
//         }

//         // For Second Triangle
//         int value = row - 1;
//         while (value)
//         {
//             cout << "* ";
//             value = value - 1;
//         }
//         cout << endl;
//         row = row + 1;
//     }


//     // For Lower Pyramid
//     int Row = 1;
//     while (Row <= n)
//     {

//         // For space
//         int Space = Row ;
//         while (Space)
//         {
//             cout << "  ";
//             Space = Space - 1;
//         }

//         // For first Triangle
//         int Value = n - Row + 1;
//         while (Value)
//         {
//             cout << "* ";
//             Value = Value - 1;
//         }

//         // For second Triangle
//         int Col = n - Row;
//         while (Col)
//         {
//             cout << "* ";
//             Col = Col - 1;
//         }
//         cout << endl;
//         Row = Row + 1;
//     }

//     return 0;
// }