// Interleave First Half Of The Queue With Second Half
// input --> {11,12,13,14,15,16,17,18,19,20}
// output -->{11,16,12,17,13,18,14,19,15,20}

#include<iostream>
#include<queue>
using namespace std;

queue<int> InterleaveHalfs(queue<int> Q,int n)
{
    // int half = Q.size()/2;
    int Half = n/2;
    queue<int> newQ;

    // step1 --> Inserted First Half of the queue in new queue
    for (int i = 0; i < Half; i++)
    {
        int val = Q.front();
        Q.pop();
        newQ.push(val);
    }

    //step2 --> Interleave input and new queue 
    while(!newQ.empty())
    {
        int val = newQ.front();
        newQ.pop();
        Q.push(val);
        val = Q.front();
        Q.pop();
        Q.push(val);
    }
    return Q;
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
    q = InterleaveHalfs(q,n);
    
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;

}