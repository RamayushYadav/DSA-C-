#include <iostream>
using namespace std;

class Dequeue
{
    int *arr;
    int Front;
    int Rear;
    int size;

public:
    Dequeue(int n)
    {
        size = n;
        arr = new int[size];
        Front = -1;
        Rear = -1;
    }

    bool pushFront(int x)
    {
        if ((Front == 0 && Rear == size - 1) || (Rear == (Front - 1) % (size - 1)))
        {
            cout << "Queue is Full" << endl;
            return false;
        }

        // for single element
        else if (Front == -1)
        {
            Front = Rear = 0;
        }

        // cyclic nature maintain
        else if (Front == 0 && Rear != size - 1)
        {
            Front = size - 1;
        }
        // normal push
        else
        {
            Front--;
        }

        arr[Front] = x;
        return true;
    }

    // same as circualr queue
    bool pushRear(int x)
    {
        if ((Front == 0 && Rear == size - 1) || (Rear == (Front - 1) % (size - 1)))
        {
            cout << "Queue is Full" << endl;
            return false;
        }

        // for single element
        else if (Front == -1)
        {
            Front = Rear = 0;
        }

        // cyclic nature maintain
        else if (Front != 0 && Rear == size - 1)
        {
            Rear = 0;
        }
        // normal push
        else
        {
            Rear++;
        }

        arr[Rear] = x;
        return true;
    }

    // same as circualr queue
    int popFront()
    {
        int ans = arr[Front];
        arr[Front] = -1;

        // if queue is empty
        if (Front == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        // single element ko pop karna hai
        else if (Front == Rear)
        {
            Front = Rear = -1;
        }

        // cyclic nature maintain
        else if (Front == size - 1)
        {
            Front = 0;
        }

        // normal pop karna hai
        else
        {
            Front++;
        }

        return ans;
    }

    int popRear()
    {
        int ans = arr[Rear];
        arr[Rear] = -1;

        // if queue is empty
        if (Front == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        // single element ko pop karna hai
        else if (Front == Rear)
        {
            Front = Rear = -1;
        }

        // cyclic nature maintain
        else if (Rear == 0)
        {
            Rear = size - 1;
        }

        // normal pop karna hai
        else
        {
            Rear--;
        }

        return ans;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[Front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }

        return arr[Rear];
    }

    bool isEmpty()
    {
        if (Front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        // (Front != 0) because (-1) modulous return karke de dega
        if ((Front == 0 && Rear == size - 1) || (Front != 0 && Rear == (Front - 1) % (size - 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()

{
    Dequeue d(20);
    d.pushFront(10);
    d.pushRear(20);

    cout << d.getFront() << endl;
    cout << d.getRear() << endl;

    cout << "poped element from front " << d.popFront() << endl;
    cout << "poped element from rear " << d.popRear() << endl;

    cout << d.isEmpty() << endl;
    cout << d.isFull() << endl;

    return 0;
}