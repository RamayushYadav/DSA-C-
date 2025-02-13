// each digit ki power 3 ka sum wahi number aaye

// we are also optimise the code with using power function
#include <iostream>
using namespace std;

int Armstrong(int digit)
{

    // count of the digit
    int count = 0;
    int temp = digit;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }
    int sum = 0;
    int rem = 0;
    // find the cube of number
    int mult;

    while (digit != 0)
    {
        mult = 1;
        rem = digit % 10;
        for (int i = 0; i < count; i++)
        {
            mult = mult * rem;
        }
        sum = sum + mult;
        digit = digit / 10;
    }
    return sum;
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ans = Armstrong(num);
    if (num == ans)
    {
        cout << "ARMSTRONG" << endl;
    }
    else
    {
        cout << "NOT ARMSTRONG NUMBER" << endl;
    }
}