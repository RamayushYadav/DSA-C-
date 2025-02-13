// Queue in STL
#include <iostream>
#include <queue>
using namespace std;

int main()

{
    queue<int> q;

    q.push(2);
    q.push(4);
    q.push(10);

    cout << "size of queue is " << q.size() << endl;

    q.pop();

    cout << "size of queue is " << q.size() << endl;

    cout << "if queue is empty " << q.empty() << endl;

    cout << "front of the queue " << q.front() << endl;

    q.pop();

    cout << "front of the queue " << q.front() << endl;
    return 0;
}