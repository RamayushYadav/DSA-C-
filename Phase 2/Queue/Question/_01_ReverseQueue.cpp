#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> q)
{
    stack<int> s;

    // queue main se element nikal kar stack main dal denge
    while(!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // stack main se element nikal kar queue main dal denge
    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
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

    Q = reverse(Q);


    while(!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    
    return 0;
}