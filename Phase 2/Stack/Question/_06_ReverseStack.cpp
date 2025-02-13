#include<iostream>
#include<stack>
using namespace std;

void InsertAtBottom(stack<int> &stack,int element)
{
    // base case
    if(stack.empty())
    {
        stack.push(element);
        return;
    }

    int num = stack.top();
    stack.pop();

    InsertAtBottom(stack,element);

    stack.push(num);
}

void reverse(stack<int> &st)
{
    // base case
    if(st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    reverse(st);

    InsertAtBottom(st,num);
}

int main()

{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(6);

    reverse(st);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}