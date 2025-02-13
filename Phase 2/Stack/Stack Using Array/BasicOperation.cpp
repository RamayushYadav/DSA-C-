// Basic Operations of Stack
#include <iostream>
using namespace std;

class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Insertion in stack
    void push(int element)
    {
        // alteast single element space is exist can't full the stack
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack is Overflow can't push any element in stack" << endl;
        }
    }
    
    // Deletion from stack
    void pop()
    {
        // alteast single element exist in stack
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack is Underflow can't pop any element from stack" << endl;
        }
    }

    // Top most element of stack
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    // When Checking Stack is Empty or Not
    bool isEmpty()
    {
        if (top == -1)
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
    Stack st(6);

    st.push(13);
    st.push(23);
    st.push(33);
    st.push(43);
    cout << st.peek() << endl;
    st.pop(); 
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Arrrrre Stack Empty ho gya bas kar" << endl;
    }
    else
    {
        cout << "Stack Empty nahi hua abhi tu pop() kar sakta hai" << endl;
    }

    return 0;
}