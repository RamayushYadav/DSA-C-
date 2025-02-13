// special number
// n = 145
// 1! + 4! + 5! = 1 + 24 + 120 = 145
// 145 is a spcial Number
#include<iostream>
using namespace std;

int fact(int n)
{
    // base case
    if(n == 0 || n == 1)
    {
        return 1;
    }

    return n * fact(n-1);
}

bool spcialNum(int n)
{
    int digit = n;
    int temp = n;
    int sum = 0,rem,factorial;
    
    while( digit != 0)
    {
        rem = digit%10;
        factorial = fact(rem);
        sum = sum + factorial; 
        digit = digit/10;
    }

    if(temp == sum)
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

    if(spcialNum(num))
    {
        cout << "SPECIAL NUMBER"<<endl;
    }
    else
    {
        cout << "NOT SPECIAL NUMBER "<<endl;
    }

    return 0;
}