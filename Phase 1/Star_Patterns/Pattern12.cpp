// Character Pattern
// A B C
// A B C
// A B C

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
//         char ch = 'A';
//         while (col <= n)
//         {
//             cout << ch << " ";
//             col = col + 1;
//             ch = ch + 1;
//         }
//         cout << endl;
//         row = row + 1;
//     }
//     return 0;
// }

// Another way
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
        while (col <= n)
        {
            char ch = 'A' + col - 1;
            cout << ch << " ";
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
    }
    return 0;
}