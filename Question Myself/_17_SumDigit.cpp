// sum digit
// num = 99, 9+9 = 18 = 1+8= 9
#include <iostream>
using namespace std;

int count(int val)
{
    int cnt = 0;
    while (val != 0)
    {
        val = val / 10;
        cnt++;
    }
    return cnt;
}

int sumDigit(int num)
{
    int sum = 0;
    int digit = num;
    while (digit != 0)
    {
        int rem = digit % 10;
        sum += rem;
        digit = digit / 10;
    }

    if (count(sum) == 1)
    {
        return sum;
    }
    else
    {
        sumDigit(sum);
    }
}

int main()

{
    int num = 99;

    // cout << count(num)<<endl;
    int ans = sumDigit(num);
    cout << ans << endl;
}
