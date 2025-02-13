#include <iostream>
using namespace std;

int power(int n)
{
    // base case
    if (n == 0)
        return 1;

    // recursive relation
    return 2 * power(n - 1);
}

int main()
{
    int n;
    cout << "Enter the power of 2 : ";
    cin >> n;

    cout << "The answer is -> " << power(n);

    return 0;
}