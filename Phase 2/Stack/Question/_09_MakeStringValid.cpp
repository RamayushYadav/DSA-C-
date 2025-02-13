// Minimum Cost To Make String Valid using stack
#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str)
{
    // odd condition means number of brackets odd nahi hone chahiye
    if ((str.length() % 2 == 1))
    {
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // agar (ch) opening bracket ho toh
        if (ch == '{')
        {
            s.push(ch);
        }

        else
        {
            // ch is closed bracket
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    // know stack contains invalid expression('b' is count for opening bracket
    //  and 'a' for closing bracket)
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }

        s.pop();
    }

    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

int main()
{
    string str = "}}{}{{{{";

    cout << findMinimumCost(str) << endl;

    return 0;
}