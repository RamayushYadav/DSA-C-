//     *
//    ***
//   *****
//  *******

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number n : ";
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        // For space
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

         // For second Triangle
        int value = row - 1;
        while (value)
        {
            cout << "* ";
            value = value - 1;
        }
        cout << endl;
        row = row + 1;
    }

    return 0;
}