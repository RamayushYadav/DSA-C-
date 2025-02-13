// getlength approach for the linked list
// if number of nodes are even then position of mid = (len/2)+1 (right node of the middle)
// if number of nodes are odd then  position of mid = (len/2)+1

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

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // first insert
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

        // last insert
        if (temp->next == NULL)
        {
            InsertAtTail(tail, d);
            return;
        }

        // insert at middle
        Node *nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
}

void display(Node *&head)
{
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

Node *getMiddle(Node *&head)
{
    int len = getLength(head);
    int ans = (len / 2) + 1;
    // int ans = (len / 2) ;

    Node *temp = head;
    int count = 1;
    // int count = 0;
    while (count < ans)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    InsertAtHead(head, 5);
    InsertAtTail(tail, 15);
    InsertAtPosition(tail, head, 3, 12);

    display(head);
    cout << "The middle node of the linked list " << getMiddle(head)->data << endl;

    return 0;
}