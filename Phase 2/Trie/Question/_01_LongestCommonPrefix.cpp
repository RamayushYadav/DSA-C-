// Longest Common Prefix in String
// M = length , N= number of string , T.C.= O(M*N), S.C. = O(M)
#include <iostream>
#include <vector>
using namespace std;

string LongestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    // for traversing all character of first string
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;

        // for comparing remaining characters of string
        // n = number of string
        for (int j = 1; j < n; j++)
        {
            // not match
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }

        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()

{
    vector<string> VS = {"coding", "codezen", "codingninja", "coders"};
    string Prefix = LongestCommonPrefix(VS, VS.size());
    cout << "The Longest Common Prefix of vector<string> is -> "
         << "'" << Prefix << "'" << endl;
    return 0;
}