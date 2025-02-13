// Number Pattern
//       1
//     2 3
//   4 5 6
// 7 8 9 10
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int row = 1;
    int value = row;
    while (row <= n)
    {
        int space = n - row;
        while (space)
        {
            cout << "  ";
            space = space - 1;
        }

        int col = 1;
        while (col <= row)
        {
            cout << value << " ";
            col = col + 1;
            value = value + 1;
        }
        cout << endl;
        row = row + 1;
    }
    return 0;
}