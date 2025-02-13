// Character Pattern
// A
// B B
// C C C

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int row = 1;
    char ch = 'A';
    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << ch << " ";
            col = col + 1;
        }
        ch = ch + 1;
        cout << endl;
        row = row + 1;
    }
return 0;
}

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
//         int col = 1;
//         while (col <= row)
//         {
//             cout << (char)('A' + row - 1) << " ";
//             col = col + 1;
//         }
//         cout << endl;
//         row = row + 1;
//     }
//     return 0;
// }