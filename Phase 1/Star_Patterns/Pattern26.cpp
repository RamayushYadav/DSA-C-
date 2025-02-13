// Number Pattern
//        1
//      1 2 1
//    1 2 3 2 1
//  1 2 3 4 3 2 1
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
        // For space
        int space1 = n - row;
        while (space1)
        {
            cout << "  ";
            space1 = space1 - 1;
        }

        // For first triangle
        int col = 1;
        while (col <= row)
        {
            cout << col << " ";
            col = col + 1;
        }

        // for second triangle
        int value = row - 1;
        while (value)
        {
            cout << value << " ";
            value = value - 1;
        }
        cout << endl;
        row = row + 1;
    }

    return 0;
}