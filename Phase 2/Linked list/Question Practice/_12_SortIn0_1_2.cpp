// sort the list in 0 1 2
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

Node *SortedIn012(Node *&head)
{
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;

    Node *temp = head;
    // store the count
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerocount++;
        }
        else if (temp->data == 1)
        {
            onecount++;
        }
        else if (temp->data == 2)
        {
            twocount++;
        }

        temp = temp->next;
    }

    // restart temp with head
    temp = head;
    // modify the list
    while (temp != NULL)
    {
        if (zerocount != 0)
        {
            temp->data = 0;
            zerocount--;
        }
        else if (onecount != 0)
        {
            temp->data = 1;
            onecount--;
        }
        else if (twocount != 0)
        {
            temp->data = 2;
            twocount--;
        }

        temp = temp->next;
    }

    return head;
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

int main()

{

    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtPosition(tail, head, 3, 0);
    InsertAtTail(tail, 1);

    display(head);
    SortedIn012(head);
    display(head);
    
    return 0;
}