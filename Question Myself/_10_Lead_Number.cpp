// Lead Number
// the sum of even digit = the sum of odd digit
//  number = 6369 , 1452
// 6 + 6 = 3 + 9 = 12
#include <iostream>
using namespace std;

bool LEAD(int num)
{
    int digit = num;
    int EvenSum = 0, OddSum = 0;
    int rem;
    while (digit != 0)
    {
        rem = digit % 10;

        // even number case
        if (rem % 2 == 0)
        {
            EvenSum = EvenSum + rem;
        }
        // odd number case
        else
        {
            OddSum = OddSum + rem;
        }

        digit = digit / 10;
    }

    if (EvenSum == OddSum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()

{
    int num;
    cout << "Enter the number ";
    cin >> num;

    if (LEAD(num))
    {
        cout << "LEAD NUMBER" << endl;
    }
    else
    {
        cout << "NOT LEAD NUMBER" << endl;
    }

    return 0;
}