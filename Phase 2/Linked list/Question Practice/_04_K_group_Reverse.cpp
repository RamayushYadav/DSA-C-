// reverse a linked list in k groups
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

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&tail, Node *&head, int d, int position)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    else
    {
        Node *temp = head;

        int count = 1;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            InsertAtTail(tail, d);
            return;
        }

        Node *nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}

Node *reverseLinkedlist(Node *&head, int k)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // step 1 reverse first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step 2 Recursion dekh lega aage
    if (forward != NULL)
    {
        head->next = reverseLinkedlist(forward, k);
    }

    // step 3 Reverse linked list ka new head return kar denge
    return prev;
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
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 5);

    InsertAtTail(tail, 15);
    InsertAtPosition(tail, head, 12, 3);

    display(head);

    head = reverseLinkedlist(head, 2);
    display(head);
    return 0;
}