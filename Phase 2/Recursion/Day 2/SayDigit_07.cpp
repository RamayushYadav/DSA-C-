// SayDigit
#include <iostream>
using namespace std;

void SayDigit(int n, string arr[])
{

    // base case
    if (n == 0)
        return;

    // processing
    int digit = n % 10;

    n = n / 10;

    // recursive relation
    SayDigit(n, arr);

    cout << arr[digit] << " ";
}

int main()

{
    string arr[10] = {"Zero","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int n;
    cout << "Enter the digit -> ";
    cin >> n;

    cout << endl;
    SayDigit(n, arr);

    return 0;
}