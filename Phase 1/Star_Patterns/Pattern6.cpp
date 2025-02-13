// Star Pattern
// *
// * *
// * * *
// * * * *

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;
//     int i = 1;
//     int count = 1;
//     while (i <= n)
//     {
//         int j = 1;
//         while (j <= i)
//         {
//             cout << "* ";
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

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
            cout << "* ";
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
    }
    return 0;
}