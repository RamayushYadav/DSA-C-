#include <iostream>
using namespace std;

bool isPrime(int n)
{

    // if(number%1 == 0 || number%temp == 0)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }

    // for (int i = 2; i < n ; i++)
    // {
    //     if(n%i == 0)
    //     {
    //         cout << i << endl;
    //         return false;
    //     }
    // }
    int temp = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            // cout << i << endl;
            temp++;
        }
    }

    if (temp > 0)
    {
        return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;

    if (isPrime(n))
    {
        cout << "PRIME NUMBER" << endl;
    }
    else
    {
        cout << "NOT PRIME NUMBER" << endl;
    }
}