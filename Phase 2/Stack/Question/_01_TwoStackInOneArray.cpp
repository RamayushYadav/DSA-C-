// two stacks implement in a single array
#include <iostream>
using namespace std;

class TwoStack
{
public:
    int top1;
    int top2;
    int *arr;
    int size;

    TwoStack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void push1(int element)
    {
        // atleast single space for element
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = element;
        }
    }

    void push2(int element)
    {
        // atleast single space for element
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = element;
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    int pop2()
    {
        if (top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

int main()

{
    TwoStack s1s2(10);
    s1s2.push1(1);
    s1s2.push2(10);

    cout << s1s2.pop1() << endl;
    cout << s1s2.pop2() << endl;

    return 0;
}