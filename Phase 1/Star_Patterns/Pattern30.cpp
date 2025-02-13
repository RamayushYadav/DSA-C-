//       1
//     2 1 2
//   3 2 1 2 3
// 4 3 2 1 2 3 4

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    // For space
    int row = 1;
    while (row <= n)
    {
        int space = n - row;
        while (space)
        {
            cout << "  ";
            space = space - 1;
        }
        // For pattern 1
        int value = row;
        while (value)
        {
            cout << value << " ";
            value = value - 1;
        }

        //  For pattern 2
        int value1 = 2;
        while (value1 <= row)
        {
            cout << value1 << " ";
            value1 = value1 + 1;
        }

        cout << endl;
        row = row + 1;
    }
    return 0;
}