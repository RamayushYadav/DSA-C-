// Character Pattern
// D
// C D
// B C D
// A B C D

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
        char ch = 'A' + n - row;
        while (col <= row)
        {
            cout << ch << " ";
            col = col + 1;
            ch = ch + 1;
        }
        cout << endl;
        row = row + 1;
    }
    return 0;
}