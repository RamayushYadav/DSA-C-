// Remove Duplicates from unsorted linked list
// 4 2 5 4 2 2(input list)
// 4 2 5(output list)
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

Node *UnsortedRemoveDuplicates(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        // yeh second node se start hogi
        Node *curr = temp->next;
        while (curr != NULL)
        {
            // find duplicates
            if (temp->data == curr->data)
            {
                Node *curr_next = curr->next;
                Node *nodeToDelete = temp;
                delete (nodeToDelete);
                curr->next = curr_next;
            }

            temp = temp->next;
        }
        return head;
    }
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

    InsertAtHead(head, 4);
    InsertAtTail(tail, 5);
    InsertAtTail(tail, 2);
    InsertAtTail(tail, 2);
    InsertAtPosition(tail, head, 4, 4);
    print(head);
    UnsortedRemoveDuplicates(head);
    print(head);

    return 0;
}