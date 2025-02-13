#include <iostream>
using namespace std;

// without recursion
int dsum(int digit)
{
    int sum = 0;
    int mod;
    while (mod != 0)
    {
        mod = digit % 10;
        sum += mod;

        digit = digit / 10;
    }

    return sum;
}

// with recursion
int ddsum(int digit, int sum1)
{
    int sum = sum1, mod;
    if (digit == 0)
    {
        return sum;
    }
    mod = digit % 10;
    sum += mod;

    ddsum(digit / 10, sum);
}

int main()
{
    int d;
    cout << "Enter digit ";
    cin >> d;

    cout << dsum(d) << endl;
    cout << ddsum(d, 0) << endl;

    return 0;
}