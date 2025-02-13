// which is divisible by 100
// if it is divisible by 4 then not divisible by 100
// divisible by 400
#include <iostream>
using namespace std;

int isLeapYear(int num)
{
    if (num % 400 == 0)
    {
        return 1;
    }
    else if (num % 4 == 0 && num % 100 != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()

{
    int year = 2021;
    if (isLeapYear(year))
    {
        cout << "LEAP YEAR" << endl;
    }
    else
    {
        cout << "NOT LEAP YEAR" << endl;
    }
}