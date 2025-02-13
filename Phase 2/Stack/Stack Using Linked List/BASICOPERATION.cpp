#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // static void push(Node *&top, int d)
    // {
    //     Node *temp = new Node(d);
    //     temp->next = top;
    //     top = temp;
    // }

    // static Node *pop(Node *&top)
    // {
    //     if (top == NULL)
    //     {
    //         cout << "Stack underflow (empty stack)!" << endl;
    //         return NULL;
    //     }
    //     Node *temp = top;
    //     top = top->next;
    //     temp->next = NULL;
    //     return temp;
    // }
};
void push(Node *&top, int d)
{
    Node *temp = new Node(d);
    temp->next = top;
    top = temp;
}

Node *pop(Node *&top)
{
    if (top == NULL)
    {
        cout << "Stack underflow (empty stack)!" << endl;
        return NULL;
    }
    Node *temp = top;
    top = top->next;
    temp->next = NULL;
    return temp;
}

Node *peek(Node *&top)
{
    return top;
}

int size(Node *&top)
{
    Node *temp = top;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

bool isEmpty(Node *&top)
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()

{
    // Node *top = NULL;

    // Node::push(top, 2);
    // Node::push(top, 3);
    // Node::push(top, 5);
    // Node *el = Node::pop(top);

    // if (el != NULL)
    // {
    //     cout << el->data << endl;
    //     delete el; // don't forget to free the memory
    // }
    Node *top = NULL;
    push(top, 2);
    push(top, 3);
    push(top, 5);

    //  cout << pop(top)->data << endl;
    Node *e1 = pop(top);
    cout << e1->data << endl;
    delete e1;
    cout << "Top Most Element " << peek(top)->data << endl;
    cout << "The Length Of Linked List " << size(top) << endl;
    if (isEmpty(top))
    {
        cout << "The Stack Is Empty" << endl;
    }
    else
    {
        cout << "The Stack Is  Not Empty" << endl;
    }
    return 0;
}