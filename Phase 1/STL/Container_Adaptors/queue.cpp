// queue is the data structure in STL which is work on the principal of FIFO(first in first out)
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;

    // Insert the element in queue
    q.push("Ramayush");
    q.push("Yadav");
    q.push("Indian");
    cout << "First element of queue : " << q.front() << endl;
    cout << "Before pop size of queue is : " << q.size() << endl;
    q.pop();
    cout << "After pop size of queue is : " << q.size() << endl;

    return 0;
}