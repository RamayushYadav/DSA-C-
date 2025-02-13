// SPY NUMBER (Sum And Product Of Digit Are Same)
// n = 1412
// sum = 1+4+1+2 = 8
// product = 1*4*1*2 = 8
#include <iostream>
using namespace std;

bool SPY(int number)
{
    int digit = number;
    int sum = 0, product = 1;
    int rem;
    while (digit != 0)
    {
        rem = digit % 10;
        sum = sum + rem;
        product = product * rem;
        digit = digit / 10;
    }
    if (sum == product)
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

    if (SPY(num))
    {
        cout << "SPY NUMBER" << endl;
    }
    else
    {
        cout << "NOT SPY NUMBER" << endl;
    }

    return 0;
}