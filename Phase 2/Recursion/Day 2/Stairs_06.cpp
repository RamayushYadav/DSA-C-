// Count ways to reach nth stairs
#include <iostream>
using namespace std;

int CountDistinctWayToClimbStair(long long nStairs)
{

    // base case
    if (nStairs < 0)
        return 0;

    if (nStairs == 0)
        return 1;

    // Recursive call
    int ans = CountDistinctWayToClimbStair(nStairs - 1) + CountDistinctWayToClimbStair(nStairs - 2);

    return ans;
}

int main()
{
    long long nStairs;
    cout << "Enter the number of stairs -> ";
    cin >> nStairs;

    cout << "The number of ways to climb stairs -> " << CountDistinctWayToClimbStair(nStairs);
    return 0;
}