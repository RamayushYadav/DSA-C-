// Super Number
// input : 175
// 1^1 + 7^2 + 5^3 = 175
#include<iostream>
using namespace std;

int power(int a,int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }

    return a * power(a,b-1);
}

int Count(int num)
{
    int cnt = 0;
    int digit = num;
    while(digit != 0)
    {
        cnt++;
        digit = digit/10;
    }
    return cnt;
}

bool Super(int num)
{
    // find count
    int count = Count(num);
    int digit = num;
    int temp = num;
    int sum = 0;
    while(digit != 0 && count != 0)
    {
        int rem = digit%10;
        // find power digit
        int poW = power(rem,count);
        count--;
        // find sum
        sum = sum + poW;
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

    if(Super(num))
    {
        cout << "SUPER NUMBER"<<endl;
    }
    else
    {
        cout << "NOT SUPER NUMBER"<<endl;
    }

    return 0;
}