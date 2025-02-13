// Number Pattern
// 1
// 2 3
// 3 4 5
// 4 5 6 7
// 5 6 7 8 9
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;
//     int row = 1;
//     while (row <= n)
//     {
//         int value = row;
//         int col = 1;
//         while (col <= row)
//         {
//             cout << value << " ";
//             col = col + 1;
//             value = value + 1;
//         }
//         cout << endl;
//         row = row + 1;
//     }
//     return 0;
// }

// Without int value another way of this pattern(HomeWork)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << col;
            col++;
        }
        cout << endl;
        row++;
    }
    return 0;
}