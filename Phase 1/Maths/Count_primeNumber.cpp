// Given an integer n,return the number of prime numbers that are strictly less than n
// This program complexity is very high 
#include <iostream>
using namespace std;

bool isPrime(int N)
{
    if (N <= 1)
    {
        return 0;
    }

    for (int i = 2; i < N; i++)
    {
        if (N % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int countPrimes(int num)
{
    int count = 0;
    for (int i = 2; i < num; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter the  number : ";
    cin >> n;

    cout << "The counting of prime number between 1 and " << n << " is : " << countPrimes(n);

    return 0;
}

