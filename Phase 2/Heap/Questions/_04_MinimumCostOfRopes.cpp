// Minimum Cost Of Ropes
#include <iostream>
#include <queue>
using namespace std;

int minCost(int arr[], int n)
{
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int cost = 0;
    // size != 1
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost = cost + sum;

        pq.push(sum);
    }

    return cost;
}

int main()

{
    int arr[4] = {4, 3, 2, 6};

    int minimumCost = minCost(arr, 4);

    cout << "MINIMUM COST IS " << minimumCost << endl;

    return 0;
}