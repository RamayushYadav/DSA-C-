// "K" Queues In An Array
#include <iostream>
using namespace std;

class KQueue
{
public:
    int n; // size of array
    int k; // number of queues
    int *Front;
    int *Rear;
    int *arr;
    int *next;
    int freespot;

    KQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        Front = new int[k];
        Rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            Front[i] = -1;
            Rear[i] = -1;
        }
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        // last position of next
        next[n - 1] = -1;

        arr = new int[n];
        freespot = 0;
    }

    // Enqueue Operation In Queue
    void Enqueue(int data, int qn)
    {
        // overflow condition
        if (freespot == -1)
        {
            cout << "No Empty Space Is Present" << endl;
            return;
        }

        // find first freespot
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // Check Wheather First Element(qn-1) because 0 base indexing
        if (Front[qn - 1] == -1)
        {
            Front[qn - 1] = index;
        }
        else
        {
            // link new element to the previous element
            next[Rear[qn - 1]] = index;
        }

        // Updata next(-1) for no freespot
        next[index] = -1;

        // Update Rear
        Rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    // Dequeue In Queue
    int dequeue(int qn)
    {
        // Underflow Check
        if (Front[qn - 1] == -1)
        {
            cout << "Queue Is Empty Can't Dequeue Any Element From Queue" << endl;
            return -1;
        }

        // Find index to pop
        int index = Front[qn - 1];

        // front ko aage badhao
        Front[qn - 1] = next[index];

        // Freespot ko manage karo
        next[index] = freespot;

        // new freespot
        freespot = index;

        return arr[index];
    }
};

int main()

{
    KQueue q(10, 3);

    q.Enqueue(10, 1);
    q.Enqueue(15, 1);
    q.Enqueue(20, 2);
    q.Enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}