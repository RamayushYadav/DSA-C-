// To reverse a number  and if the number is not in range [-pow(2,31) to pow(2,31)-1] than return 0 and find the sum of digit
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if ((ans > INT32_MAX / 10) || (ans < INT32_MIN / 10))
        {
            cout << "0";
            return 0;
            // ans = INTMAX_MAX/10 * 10 than ans = INTMAX_MIN
        }
        ans = ans * 10 + digit;
        n = n / 10;
    }
    cout << "The reverse is : " << ans << endl;

    int m;
    int sum = 0;
    cout << "Enter the value of m : ";
    cin >> m;
    while (m != 0)
    {
        int digit = m % 10;
        sum = sum + digit;
        m = m / 10;
    }
    cout << "The sum of digit of : " << sum << endl;

    return 0;
}