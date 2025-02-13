// Kth Largest Sum Sub Array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    vector<int> sumStore;
    int n = arr.size();
    // Calculating all subarray sums
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            sumStore.push_back(sum);
        }
    }
    // Sorting the sums in descending order
    sort(sumStore.begin(), sumStore.end());

    // Return the kth largest sum
    return sumStore[sumStore.size() - k];

    // Return the kth largest sum
    // return sumStore[k - 1]; // Subtract 1 to adjust for 0-based indexing
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

    int kthlargest = getKthLargest(V, k);

    cout << k << "th Largest sum is -> " << kthlargest << endl;

    return 0;
}