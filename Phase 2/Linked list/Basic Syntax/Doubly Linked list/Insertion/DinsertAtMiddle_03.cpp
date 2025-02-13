// Insert At Middle in Doubly Linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertAtPosition(Node *&tail, Node *&head, int d, int position)
{
    // first position
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    // insert node ke ek position pahale
    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // insert at last
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // insert at middle
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void print(Node *&head)
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
    Node *node1 = new Node(10);

    Node *tail = node1;
    Node *head = node1;

    InsertAtHead(head, 5);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 20);
    print(head);
    InsertAtPosition(tail, head, 12, 3);
    print(head);

    return 0;
}