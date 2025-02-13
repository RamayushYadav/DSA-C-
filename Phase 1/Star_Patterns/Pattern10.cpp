// Number Pattern
// 1
// 2 1
// 3 2 1
// 4 3 2 1
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
//             value = value - 1;
//         }
//         cout << endl;
//         row = row + 1;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << (i - j + 1) << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}