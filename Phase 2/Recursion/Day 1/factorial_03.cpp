#include <iostream>
using namespace std;

int factorial(int n)
{
    // base case
    if (n == 0)
        return 1;

    // Recursive relation
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    cout << "The factorial is -> " << factorial(n);

    return 0;
}