// N Stack Insertion In An Array
#include<iostream>
using namespace std;

class NStack
{
    // declare three arrays
    int *arr;
    int *top;
    int *next;

    // n is number of stack s is size of array
    int n,s;

    int freespot;


    public:
    // Initialize your data structure(N number of stack, S- size of array)
    NStack(int N,int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top ko initialize kar denge
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next ko initialize kar denge
        for (int i = 0; i < s; i++)
        {
            next[i] = i+1;
        }
        // update last index of next array with -1
        next[s-1] = -1;

        // initialize freespot with 0
        freespot = 0;
        
    }

    // push 'X' into the Mth Stack, return true if it get pushed
    bool push(int x,int m)
    {
        // check for overflow
        if(freespot == -1)
        {
            return false;
        }

        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert element into array
        arr[index] = x;

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    // pop top element from the Mth stack,Return -1 if the stack is empty
    int pop(int m)
    {
        //check underflow
        if(top[m-1] == -1)
        {
            return -1;
        }

        // index nikal lenge
        int index = top[m-1];

        top[m-1] = next[index];
        
        // update next
        next[index] = freespot;

        freespot = index;

        return arr[index];
    }

    // void display(int m)
    // {
    //     if (top[m - 1] == -1)
    //     {
    //         cout << "Stack " << m << " is empty." << endl;
    //         return;
    //     }

    //     cout << "Stack " << m << " elements: ";
    //     int index = top[m - 1];
    //     while (index != -1)
    //     {
    //         cout << arr[index] << " ";
    //         index = next[index];
    //     }
    //     cout << endl;
    // }

};

int main()

{
    NStack s(3,6);

    s.push(10,1);
    s.push(20,1);
    s.push(30,2);
    s.pop(1);
    s.pop(2);

    // s.display(1);
    // s.display(2);

    return 0;
}