// Without Using Queue
// Interleave First Half Of The Queue With Second Half
// input --> {11,12,13,14,15,16,17,18,19,20}
// output -->{11,16,12,17,13,18,14,19,15,20}
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> InterLeaveHalfs(queue<int> q, int n)
{
    int half = n / 2;
    stack<int> s;

    // step 1 first of queue into stack
    for (int i = 0; i < half; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step 2 stack element ko queue main wapas push karo
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // step 3 queue main first half element pop karo or push karo
    for (int i = 0; i < half; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    // step 4 queue ka first half stack main push karo
    for (int i = 0; i < half; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    // step 5 interleave algo laga do
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}

int main()

{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    int n = q.size();
    q = InterLeaveHalfs(q, n);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}