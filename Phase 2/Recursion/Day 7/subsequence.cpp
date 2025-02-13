#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{
    // base case
    if (index >= str.length())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(str, output, index + 1, ans);

    // include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);
}

vector<string> subSequences(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main()
{
    string str = "abc";
    vector<string> subsequences = subSequences(str);

    for (const auto &subsequence : subsequences)
    {
        cout << subsequence << " ";
    }

    //  string str;
    // cout << "Enter a string: ";
    // cin >> str; // Take user input for the string

    // vector<string> subsequences = subSequences(str);

    // cout << "Subsequences:" << endl;
    // for (const auto& subsequence : subsequences) {
    //     cout << subsequence << " ";
    // }

    return 0;
}
