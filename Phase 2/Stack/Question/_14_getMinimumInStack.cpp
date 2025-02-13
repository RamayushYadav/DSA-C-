// Get Minimum Element in Stack (in O(1) time and space complexity)
#include<iostream>
#include<stack>
using namespace std;

class SpecialStack
{
    // define the data member
    stack<int> s;
    int mini;

    public:
    void push(int curr)
    {
        // agar pahala element push kar rahe hai
        if(s.empty())
        {
            s.push(curr);
            // update mini
            mini = curr;
        }
        else
        {
            // jo element push kar rahe hai vo mini se small hai
            if(curr < mini)
            {
                int val = 2*curr- mini;
                s.push(val);
                // mini update
                mini  = curr;
            }
            else
            {
                // agar element bada hai
                s.push(curr);
            }
        }

    }

    int pop()
    {
        // underflow check
        if(s.empty())
        {
            return -1;
        }
        // stack empty nahi hai matlab pop kar sakte hai
        else
        {
            // 
            int curr = s.top();
            s.pop();
            // curr ko pop kar rahe hai agar curr bada hai mini element of stack sai toh normal pop karenge

            if(curr > mini)
            {
                return curr;
            }
            else
            {
                // curr hi minimum element hai toh mini ko update kar denge
                int prevMin  = mini;
                int val = 2*mini-curr;
                mini = val;
                return prevMin;
            }
             
        }

    }

    int top()
    {
        if(s.empty())
        {
            return -1;
        }

        int curr = s.top();

        // hamne stack main exact number nahi dala hoga
        if(curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }

    }

    bool isEmpty()
    {
        return s.empty();
    }

    int getMin()
    {
        if(s.empty())
        {
            return -1;
        }

        return mini;
    }
};

int main()

{
    SpecialStack sps;
    sps.push(5);
    sps.push(3);
    sps.push(8);
    sps.push(2);
    sps.push(4);

    
    cout << sps.pop() << endl;
    
    cout << "Before pop Minimum element "<<sps.getMin() << endl;

    cout << "pop the minimum element " << sps.pop() << endl;

    cout << "After pop Minimum element "<<sps.getMin() << endl; 
    
    cout << "top of the stack " << sps.top() << endl;
    return 0;
}