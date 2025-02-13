// print nth term of fibonacci series
// 0 ,1 ,1 ,2 ,3 ,5 ,8 ,----
#include <iostream>
using namespace std;

int fibo(int n)
{
    // base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // recursive relation
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    cout << "Enter the nth term -> ";
    cin >> n;

    cout << "In a fibonacci series the value of " << n << " th term is -> " << fibo(n);

    return 0;
}