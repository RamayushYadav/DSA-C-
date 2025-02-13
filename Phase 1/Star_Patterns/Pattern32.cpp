//    ********
//   ****  ****
//  ****    ****
// ****      ****
// ****      ****
//  ****    ****
//   ****  ****
//    ********
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

        // For first space
        int value = n - row;
        while (value)
        {
            cout << "  ";
            value = value - 1;
        }

        // For first star pattern
        int col = n;
        while (col)
        {
            cout << "* ";
            col = col - 1;
        }

        // For space 2
        int value1 = row - 1;
        while (value1)
        {
            cout << "  ";
            value1 = value1 - 1;
        }

        // For space 3
        int value2 = row - 1;
        while (value2)
        {
            cout << "  ";
            value2 = value2 - 1;
        }

        // For second star pattern
        int col1 = n;
        while (col1)
        {
            cout << "* ";
            col1 = col1 - 1;
        }

        cout << endl;
        row = row + 1;
    }


    // For Lower Part
    int Row = 1;
    while (Row <= n)
    {

        // For first space
        int Value = Row - 1;
        while (Value)
        {
            cout << "  ";
            Value = Value - 1;
        }

        // For first Star Pattern
        int Col = n;
        while (Col)
        {
            cout << "* ";
            Col = Col - 1;
        }

        // For second space
        int Value1 = n - Row;
        while (Value1)
        {
            cout << "  ";
            Value1 = Value1 - 1;
        }

        // For Third space
        int Value2 = n - Row;
        while (Value2)
        {
            cout << "  ";
            Value2 = Value2 - 1;
        }

        // For second Star Pattern
        int Col1 = n;
        while (Col1)
        {
            cout << "* ";
            Col1 = Col1 - 1;
        }
        cout << endl;
        Row = Row + 1;
    }

    return 0;
}