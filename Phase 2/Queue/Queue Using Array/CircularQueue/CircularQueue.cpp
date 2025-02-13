// Circular Queue
#include <iostream>
using namespace std;

class CircularQueue
{
    int *arr;
    int rear;
    int qfront;
    int size;

public:
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    bool enqueue(int value)
    {
        // queue full hai  kya
        if ((qfront == 0 && rear == size - 1) || (rear == qfront - 1))
        // if ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1) % (size - 1)))
        {
            cout << "Queue is Full" << endl;
            return false;
        }

        // first elememt to push
        else if (qfront == -1)
        {
            qfront = rear = 0;
            arr[rear] = value;
        }

        // rear end main hai or front zeroth index par nahi hai
        // to maintain cyclic nature
        else if (rear == size - 1 && qfront != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        // normal push
        else
        {
            rear++;
            arr[rear] = value;
        }
        return true;
    }

    int dequeue()
    {
        int ans = arr[qfront];
        arr[qfront] = -1;
        // queue emtpy toh nahi hai
        if (qfront == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        // single element hai queue main usse hi pop karna hai

        else if (qfront == rear)
        {
            qfront = rear = -1;
        }

        // agar front last main chala gaya fir pop() karna hai starting position se
        // to maintain cyclic nature
        else if (qfront == size - 1)
        {
            qfront = 0;
        }

        // normal pop
        else
        {
            qfront++;
        }
        return ans;
    }
};

int main()
{
    CircularQueue cq(4);
    cout << cq.enqueue(10) << endl;
    cout << cq.enqueue(20) << endl;
    cout << cq.enqueue(30) << endl;
    cout << cq.enqueue(40) << endl;
    cout << cq.enqueue(40) << endl;
    cout << cq.enqueue(40) << endl;

    cout << cq.dequeue() << endl;

    return 0;
}