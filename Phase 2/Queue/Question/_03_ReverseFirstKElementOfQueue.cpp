// Reverse First K elements of Queue
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> ModifyQueue(queue<int> q,int k)
{
    stack<int> s;
    // pop first k elements from queue and put into stack
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    // Fetch from stack and put into queue
    while(!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    // Fetch first (n-k) element from Q and push back into it
    int t = q.size() - k;
    while(t--)
    {
        int val = q.front();
        // first se delete karo 
        q.pop();
        // last main insert kar do
        q.push(val);
    }
        return q;
}

int main()
{
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);

    Q = ModifyQueue(Q,3);

    while(!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    
   

    return 0;

}