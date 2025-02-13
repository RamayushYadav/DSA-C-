// Insert The Element Bottom In The Stack
#include <iostream>
#include <stack>
using namespace std;

void InsertBottom(stack<int> &inputstack, int element)
{
    // base case
    if (inputstack.empty())
    {
        inputstack.push(element);
        return;
    }

    int num = inputstack.top();
    inputstack.pop();

    // recursive call
    InsertBottom(inputstack, element);

    inputstack.push(num);
}

int main()

{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(6);

    InsertBottom(st, 9);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}