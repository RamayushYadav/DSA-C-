// nCr = n! / (r! * n-r!)
#include <iostream>
using namespace std;

int fact(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r)
{
    int numerator = fact(n);
    int denomantor = fact(r) * fact(n - r);
    int ans = numerator / denomantor;
    return ans;
}

int main()
{
    int n, r;
    cout << "Enter the value of n : ";
    cin >> n;
    cout << "Enter the value of r : ";
    cin >> r;
    cout << "The nCr is : " << nCr(n, r);
    return 0;
}