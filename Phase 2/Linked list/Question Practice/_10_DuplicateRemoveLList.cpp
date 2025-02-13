// remove duplicates from linked list
// input list --> 1 2 2 3 3 3 3 4
// output list --> 1 2 3 4
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
    // insert at first
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

        // insert at tail
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

Node *RemoveDuplicates(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return NULL;
    }

    // non empty list 1 or more than one node exist in the linked list
    Node *curr = head;
    
    while (curr != NULL)
    {
        // duplicates (curr->next) NULL nahi ho iska means single node list na ho
        // toh node ka next delete nahi ho payega
         if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *NodeToDelete = curr->next;
            delete (NodeToDelete);
            curr->next = next_next;
        }
        // not duplicates
        //(curr->data != curr->next->data)
        else
        {
            curr = curr->next;
        }
    }
    // new linked list ka head return kar denge
    return head;
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
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;

    InsertAtHead(head, 1);

    InsertAtTail(tail, 2);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 3);
    InsertAtTail(tail, 4);

    InsertAtPosition(tail, head, 5, 3);

    print(head);
    // remove function call
    RemoveDuplicates(head);
    print(head);

    return 0;
}
