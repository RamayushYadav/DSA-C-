// You are given a three integers 'X','N' and 'M'. Your task is to find ('X' ^ 'N') % 'M'.
#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m)
{
    int res = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            // odd
            res = (1LL * (res) * (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;
    }
    return res;
}

int main()
{
    int X, N, M;
    cout << "Enter the base no. X : ";
    cin >> X;
    cout << "ENter the power N : ";
    cin >> N;
    cout << "Enter the modular M : ";
    cin >> M;

    cout << "Answer value is : " << modularExponentiation(X, N, M);
    return 0;
}