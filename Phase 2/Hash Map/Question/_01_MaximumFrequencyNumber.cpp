// Maximum Frequency Number
// find the maximum count in an array
// if two number have same frequency which is max than the number should be in the array first
// it will return
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> M;
    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < n; i++)
    {
        M[arr[i]]++;
        maxFreq = max(maxFreq, M[arr[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxFreq == M[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main()

{
    vector<int> V{1, 2, 3, 1, 2};
    int n = V.size();

    cout << "MAXIMUM FREQUENCY NUMBER IS " << maximumFrequency(V, n) << endl;
    return 0;
}