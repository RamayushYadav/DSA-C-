// Bitwise Operator and left and right shift

// Pre_increment (++i)
// Pre_decrement (--i)

// Post_increment (i++)
// Post_decrement (i--)

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of b : ";
    cin >> b;

    // AND Operator
    cout << "AND Operator : " << (a & b) << endl;

    // OR Operator
    cout << "OR Operator : " << (a | b) << endl;

    // NOT Operator
    cout << "NOT Operator : " << ~a << endl;

    // XOR Operator
    cout << "XOR Operator : " << (a ^ b) << endl;

    // Right shift
    cout << (17 >> 1) << endl;
    cout << (17 >> 2) << endl;

    // Left shift
    cout << (19 << 1) << endl;
    cout << (21 << 2) << endl;

    return 0;
}
