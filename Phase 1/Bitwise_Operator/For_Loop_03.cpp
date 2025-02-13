// Prime Number (break)
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    bool isPrime = 1;
    for (int i = 2; i < n; i++)
    {
        // rem 0, not a prime
        if (n % i == 0)
        {
            isPrime = 0;
            // agar 2 se hi remainder 0 ho toh aage loop badhane ki jarurat nahi isliye break use kiya
            break;
        }
    }

    if (isPrime == 0)
    {
        cout << "The Number is not prime";
    }
    else
    {
        cout << "The Number is prime";
    }

    return 0;
}