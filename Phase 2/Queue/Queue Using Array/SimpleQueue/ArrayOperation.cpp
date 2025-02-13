// Queue using array
#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        // if queue is full
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // empty ho queue toh
        if (rear == qfront)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            // -1 for empty space
            arr[qfront] = -1;
            qfront++;

            // agar deletion karte hue qfront or rear equal ho jaye toh previous empty space
            // ko  use karne ke liye (rear or qfront ko zero se start karenge)
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int front()
    {
        //  agar element inserted nahi hai
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(22);
    q.enqueue(32);
    q.enqueue(42);
    q.enqueue(52);

    cout << "Delelted element qfrom queue " << q.dequeue() << endl;

    cout << "qfront of the queue " << q.front() << endl;

    cout << "if queue is empty or not " << q.isEmpty() << endl;

    return 0;
}