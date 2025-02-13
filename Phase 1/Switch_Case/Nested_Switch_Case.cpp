//// Nested Switch Case in C++

#include <iostream>
using namespace std;
int main()
{
    int num = 1;
    char ch = '1';

    switch (ch)
    {
    case 1:
        cout << "First" << endl;
        break;

    case '1':
        switch (num)
        {
        case 1:
            cout << "Value of num : " << num << endl;
            break;
        }
        break;

    default:
        cout << "It is default case" << endl;
        break;
    }
    return 0;
}
