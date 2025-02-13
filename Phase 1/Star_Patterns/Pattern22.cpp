// Number Pattern
// 1 1 1 1
//   2 2 2
//     3 3
//       4

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
        int space = row - 1;
        while (space)
        {
            cout << "  ";
            space = space - 1;
        }

        int col = 1;
        while (col <= n - row + 1)
        {
            cout << row<<" ";
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
    }
    return 0;
}