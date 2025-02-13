// two create three linked list and merge them a new list become sorted list
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

// Smaller lists function for sorting linked list
void InsertAtShortTail(Node *&tail, Node *&curr)
{
    tail->next = curr;
    // new tail curr hai
    tail = curr;
    // tail->next=NULL;
}

Node *SortList(Node *&head)
{
    // create dummy nodes initialize with -1
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // create separate lists for 0s,1s,2s
    while (curr != NULL)
    {
        int value = curr->data;

        if (value == 0)
        {
            InsertAtShortTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            InsertAtShortTail(oneTail, curr);
        }
        else if (value == 2)
        {
            InsertAtShortTail(twoTail, curr);
        }

        curr = curr->next;
    }
    


    // merge 3 sublists

    // 1s list is not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    // 1s list is empty
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;

    twoTail->next = NULL;

    // setup head of new merged list
    head = zeroHead->next;

    // memory free of dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // returning the head of new list
    return head;
}

int main()

{
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtPosition(tail, head, 3, 0);
    InsertAtTail(tail, 0);

    display(head);

    SortList(head);

    display(head);

    return 0;
}