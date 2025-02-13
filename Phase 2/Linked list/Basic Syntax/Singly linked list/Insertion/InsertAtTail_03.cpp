// insert at end in linked list
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
};

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    // tail = tail->next;
    tail = temp;
}

void display(Node *&ptr)
{
    Node *temp = ptr;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()

{
    Node *node = new Node(10);

    display(node);
    insertAtTail(node, 20);
    display(node);
    return 0;
}