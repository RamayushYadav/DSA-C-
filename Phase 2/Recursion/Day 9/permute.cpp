// // permutaion array
// #include <iostream>
// #include <vector>
// using namespace std;

// void solve(vector<int> nums, vector<vector<int>> &ans, int index)
// {
//     if (index >= nums.size())
//     {
//         ans.push_back(nums);
//         return;
//     }

//     for (int j = index; j < nums.size(); j++)
//     {
//         swap(nums[index], nums[j]);
//         solve(nums, ans, index + 1);
//         swap(nums[index], nums[j]);
//     }
// }

// vector<vector<int>> permute(vector<int> nums)
// {
//     vector<vector<int>> ans;
//     int index = 0;

//     solve(nums, ans, index);
//     return ans;
// }

// int main()
// {
//     int x;
//     vector<int> V;

//     while (true)
//     {
//         cout << "Enter the integer array -> ";
//         cin >> x;

//         if (x == -1)
//         {
//             break;
//         }
//         V.push_back(x);
//     }

//     vector<vector<int>> perMute = permute(V);

//     for (const auto &perMutes : perMute)
//     {
//         for (int num : perMutes)
//         {
//             cout << num;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// permutaion string
#include <iostream>
#include <vector>
using namespace std;

void solve(string nums, vector<string> &ans, int index)
{
    if (index >= nums.length())
    {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[j]);
    }
}

vector<string> permute(string nums)
{
    vector<string> ans;
    int index = 0;

    solve(nums, ans, index);
    return ans;
}

int main()
{
    string str;
    cout << "Enter the string -> ";
    cin >> str;

    for (const auto perMute : permute(str))
    {
        cout << perMute << " ";
    }
    return 0;
}
