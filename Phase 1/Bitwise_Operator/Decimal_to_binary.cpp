// Convert Decimal to Binary
// Compiler Issues In This Program
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int ans = 0;
    int i = 0;

    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }

    cout << "Answer is : " << ans;

    return 0;
}

// To convert negative number into binary