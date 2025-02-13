// Find First Non-Repeating Character of String
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // increase count
        count[ch]++;

        // queue main push karo character
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // repeating character
                q.pop();
            }
            else
            {
                // non- repeating character mil gaya
                ans.push_back(q.front());
                break;
            }
        }

        // agar queue empty ho jaye
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()

{
    string str = "aabc";

    cout << FirstNonRepeating(str);

    return 0;
}