// Redundant Brackets in Expression using stack
#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // agar string main openning bracket or koi operator hai toh stack main usse push kardenge
        if (ch == '(' || ch == '+' || ch == '*' || ch == '/' || ch == '-')
        {
            st.push(ch);
        }

        // agar closing brackets ho or {ya lower case letter(lowercase ko ignore kar denge)}
        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '*' || top == '/' || top == '-')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                {
                    return true;

                }

                st.pop();
            }
        }
    }
    return false;
}

int main()

{
    string str = "(a+b)";

    if (findRedundantBrackets(str))
    {
        cout << "The Brackets Are Redundant" << endl;
    }
    else
    {
        cout << "The Brackets Are Not Redundant" << endl;
    }

    return 0;
}
