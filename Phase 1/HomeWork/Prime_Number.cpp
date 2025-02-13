// which divisible by 1 and itelf
// example = 7
#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= num - 1; i++)
    {
        if (num % i == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;

    if (isPrime(n))
    {
        cout << "PRIME";
    }
    else
    {
        cout << "NOT PRIME";
    }

    return 0;
}