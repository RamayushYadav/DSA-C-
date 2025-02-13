// 5
// print 5 4 3 2 1
#include <iostream>
using namespace std;

// Tail Recursion(5 4 3 2 1)
void printCounting(int n)
{
    // base case
    if (n == 0)
        return;

    // processing
    cout << n << endl;

    // recursive relation
    printCounting(n - 1);
}

// // Head Recursion(1 2 3 4 5)
// void printCounting(int n)
// {
//     // base case
//     if (n == 0)
//         return;

//     // recursive relation
//     printCounting(n - 1);

//     // processing
//     cout << n << endl;
// }

int main()
{
    int n;
    cout << "Enter the number to print the counting -> ";
    cin >> n;

    printCounting(n);
    return 0;
}