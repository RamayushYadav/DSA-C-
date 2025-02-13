// Delete Middle Element of The Stack
#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive Call
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;

    solve(inputStack, count, N);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(9);
    s.push(4);
    s.push(1);
    deleteMiddle(s, 5);

    // Print the modified stack
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}