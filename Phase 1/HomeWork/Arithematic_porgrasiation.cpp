#include <iostream>
using namespace std;

int AP(int num)
{
    int ans = (3 * num) + 7;
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    cout << AP(n);

    return 0;
}