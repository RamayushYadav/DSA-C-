// Priority_Queue --> This is that type of queue which  have default element highest
// default priority queue is in max heap
// it is also convert into mini heap
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Implementation of max heap priority queue
    priority_queue<int> maxi;
    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(4);
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    // Implementation of min heap priority queue
    priority_queue<int, vector<int>, greater<int>> mini;
    mini.push(5);
    mini.push(3);
    mini.push(2);
    mini.push(4);
    int m = mini.size();
    for (int i = 0; i < m; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    return 0;
}