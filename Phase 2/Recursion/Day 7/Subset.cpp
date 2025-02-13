#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subSets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main()
{
    vector<int> nums;
    int x;

    // Taking input until a specific value is entered (e.g., -1 to stop)
    while (true)
    {
        cout << "Enter a number (-1 to stop): ";
        cin >> x;
        if (x == -1)
        {
            break; // Stop taking input
        }
        nums.push_back(x);
    }

    vector<vector<int>> subsets = subSets(nums);

    // Displaying all subsets
    for (const auto &subset : subsets)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

// Enter a number (-1 to stop): 1
// Enter a number (-1 to stop): 2
// Enter a number (-1 to stop): 3
// Enter a number (-1 to stop): -1
