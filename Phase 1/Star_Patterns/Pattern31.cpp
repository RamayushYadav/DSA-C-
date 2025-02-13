// *       *
// **     **
// ***   ***
// *********
// *********
// ***   ***
// **     **
// *       *
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    // For Upper Part
    int row = 1;
    while (row <= n)
    {

        // For first triangle
        int col = 1;
        while (col <= row)
        {
            cout << "* ";
            col = col + 1;
        }

        // For first space
        int space = n - row;
        while (space)
        {
            cout << "  ";
            space = space - 1;
        }

        // For second space
        int space1 = n - row;
        while (space1)
        {
            cout << "  ";
            space1 = space1 - 1;
        }
        // For second triangle
        int value = 1;
        while (value <= row)
        {
            cout << "* ";
            value = value + 1;
        }
        cout << endl;
        row = row + 1;
    }


    // For Lower Part
    int Row = 1;
    while (Row <= n)
    {

        // For first triangle
        int Value = n - Row + 1;
        while (Value)
        {
            cout << "* ";
            Value = Value - 1;
        }

        // For first space
        int Space = Row - 1;
        while (Space)
        {
            cout << "  ";
            Space = Space - 1;
        }
        // For second space
        int Space1 = Row - 1;
        while (Space1)
        {
            cout << "  ";
            Space1 = Space1 - 1;
        }

        // For second triangle
        int Col = n - Row + 1;
        while (Col)
        {
            cout << "* ";
            Col = Col - 1;
        }
        cout << endl;
        Row = Row + 1;
    }
    
    return 0;
}