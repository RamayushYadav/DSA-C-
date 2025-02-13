#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string Expression)
{
    stack<int> st;
    for (int i = 0; i < Expression.length(); i++)
    {
        // opening bracket, stack push
        // if closing bracket, stackTop check and pop

        char ch = Expression[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // for closing bracket
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()

{
    string str = "{[()]}";
    if (isValidParenthesis(str))
    {
        cout << "This is Valid Expression" << endl;
    }
    else
    {
        cout << "This is not Valid Expression" << endl;
    }
}