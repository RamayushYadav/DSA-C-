// increment function create a copy of (n)
//  so the value of n in main function should not be change this is known as "pass by value"
#include <iostream>
using namespace std;

void increment(int n)
{
    n++;
}

int main()
{
    int n = 4;
    increment(n);
    cout << n;
    return 0;
}