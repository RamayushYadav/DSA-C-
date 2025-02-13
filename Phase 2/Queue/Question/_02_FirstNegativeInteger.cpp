// first negative integer of k size window
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    // yeh deque negative elements ki indexing store karke rakhegi
    deque<long long int> dq;
    vector<long long> ans;

    // process first window of "K" size
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // stored answer of first "K" sized window
    //  iska matlab ek element toh present hai queue main
    if (dq.size() > 0)
    {
        // negative element store kar lega
        ans.push_back(A[dq.front()]);
    }
    else
    {
        // negative nahi mila toh 0 store kar lega
        ans.push_back(0);
    }

    // process for remaining elements
    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        // Addition
        // agar koi negative element hai
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
 
        // answer ko store kara lenge
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            // agar  negative element nahi milta hai toh
            ans.push_back(0);
        }
    }
    return ans;
}

int main()

{
    long long int A[] = {-8, 2, 3, -6, 10};

    for (const auto &prnt : printFirstNegativeInteger(A, 5, 2))
    {
        cout << prnt << " ";
    }

    return 0;
}