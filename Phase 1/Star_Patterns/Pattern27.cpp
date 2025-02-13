// Number and Star Pattern Combined

// 1 2 3 4 5 5 4 3 2 1
// 1 2 3 4 * * 4 3 2 1
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1

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
        // First Triangle
        int col = 1;
        while (col <= n - row + 1)
        {
            cout << col << " ";
            col = col + 1;
        }

        // Second Triangle
        int value = row - 1;
        while (value)
        {
            cout << "* ";
            value = value - 1;
        }

        // Third Triangle
        int value1 = row - 1;
        while (value1)        {
            cout << "* ";
            value1 = value1 - 1;
        }

        // Fourth Triangle
        int col1 = n - row + 1;
        while (col1)
        {
            cout << col1 << " ";
            col1 = col1 - 1;
        }

        cout << endl;
        row = row + 1;
    }

    return 0;
}