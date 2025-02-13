// insert at first in the linked list
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

void insertionAtHead(Node *&head, int d)

{
    // new node creation
    Node *temp = new Node(d);
    temp->next = head;
    // temp aab new head ban gaya hai
    head = temp;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()

{
    Node *Head = new Node(10);

    display(Head);

    insertionAtHead(Head, 5);

    display(Head);

    return 0;
}