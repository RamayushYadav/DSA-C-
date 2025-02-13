// sort the stack
#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num)
{
    // base case
    // if (stack.empty() || (!stack.empty() && stack.top() < num))
    if(stack.empty() || stack.top() < num)
    {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    // recursive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    sortedInsert(st, num);
}

int main()
{
    stack<int> s;

    s.push(3);
    s.push(1);
    s.push(9);
    s.push(6);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}