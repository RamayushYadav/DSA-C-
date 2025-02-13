// Character Pattern
// A
// B C
// D E F
// G H I J
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int row = 1;
    char value = 'A';
    while (row <= n)
    {
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