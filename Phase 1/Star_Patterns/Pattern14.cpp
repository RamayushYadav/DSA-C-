// Character Pattern
// A B C
// B C D
// C D E

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
        char ch = 'A' + row + col - 2;
        // char ch = row + col -1 + 'A' - 1;
        while (col <= n)
        {
            cout << ch;
            col = col + 1;
            ch = ch + 1;
        }
        cout << endl;
        row = row + 1;
    }
    return 0;
}

