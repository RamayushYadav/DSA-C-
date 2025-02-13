// Optimise solution using Seive of Eratosthenes
//  0 <= n <= 5 * 10^6
#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n)
{
    int count = 0;
    // create a vector array considered all elements is to be prime (-1) index wali problem face na karni padhe
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;
          
          // numbers in table must be not prime
            for (int j = 2 * i; j < n; j = j + i)
            { 
                prime[j] = 0;
            }
        }
    }
    return count;
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;

    cout << "The counting of prime number between 1 and " << num << " is : " << countPrimes(num);

    return 0;
}