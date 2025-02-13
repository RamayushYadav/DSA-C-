// kth Largest Sum SubArray
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargestSum(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> mini;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (mini.size() < k)
            {
                mini.push(sum);
            }
            else
            {
                if (sum > mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return mini.top();
}

int main()

{
    vector<int> V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(5);
    V.push_back(4);
    V.push_back(3);

    int k = 4;

    int kthlargest = kthLargestSum(V, k);

    cout << k << "th Largest sum is -> " << kthlargest << endl;

    return 0;
}