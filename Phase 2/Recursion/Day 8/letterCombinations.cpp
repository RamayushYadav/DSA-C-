// letter combinations of a phone number
// 0 = "" , 1 = "", 2 = "abc", 3 = "def", 4 = "ghi",
// 5 = "jkl", 6 = "mno", 7 = "pqrs", 8 = "tuv", 9 = "wxyz"

// example = "34"(3 = "def", 4 = "ghi")
// "dg","dh","di","eg","eh","ei","fg","fh","fi"

#include <iostream>
#include <vector>
using namespace std;

void solve(string digits, string output, int index, vector<string> &ans, string mapping[])
{
    // base case
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    // i index find karna
    int number = digits[index] - '0';
    // i index ko mapping array main find karna
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;

    if (digits.length() == 0)
    {
        return ans;
    }

    string output = "";
    int index = 0;

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, ans, mapping);

    return ans;
}

int main()
{
    string str;
    cout << "Enter the string digits -> ";
    cin >> str;

    for (const auto &lettercombinations : letterCombinations(str))
    {
        cout << lettercombinations << " ";
    }

    return 0;
}
