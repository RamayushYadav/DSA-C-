// Niven or(Harshad) Number in base 10 (Ramanujan Number)
// A Number which is fully divisible by the sum of its digit
// example = 18
// sum = 1 + 8 = 9, num%sum (18%9) == 0
#include <iostream>
using namespace std;

bool Niven(int num)
{
    int digit = num;
    int temp = num;
    int rem;
    int sum = 0;
    while (digit != 0)
    {
        rem = digit % 10;
        sum = sum + rem;
        digit = digit / 10;
    }

    if (temp % sum == 0)
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

    if (Niven(num))
    {
        cout << "NIVEN NUMBER" << endl;
    }
    else
    {
        cout << "NOT NIVEN NUMBER" << endl;
    }

    return 0;
}