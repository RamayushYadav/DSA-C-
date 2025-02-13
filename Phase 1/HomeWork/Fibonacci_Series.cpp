#include <iostream>
using namespace std;

int fibo(int n1)
{
    if (n1 == 1 || n1 == 2)
    {
        return 1;
    }
    int ans1 = fibo(n1 - 1);
    int ans2 = fibo(n1 - 2);
    int ans = ans1 + ans2;
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "The fibonacci series is : " << fibo(n);
    return 0;
}