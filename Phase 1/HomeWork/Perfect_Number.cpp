// Perfect number
// example  = 6
// 1 + 2 + 3 = 6
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == n)
    {
        cout << "PERFECT";
    }
    else
    {
        cout << "NOT PERFECT";
    }

    return 0;
}