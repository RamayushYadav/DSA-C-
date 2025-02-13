// reverse a singly linked list
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

void reverse(Node *&head, Node *&curr, Node *&prev)
{
    // base case for empty list
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;

    reverse(head, forward, curr);

    curr->next = prev;
}

Node *reverseLinkedList(Node *&head)
{

    Node *prev = NULL;
    Node *curr = head;

    reverse(head, curr, prev);

    return head;
}

/* Reverse list in another way

Node *reverse1(Node* &head)
{
    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* chotaHead = reverse1(head->next);
    
    head->next->next = head;
    
    head->next = NULL;

    return chotaHead;

}

Node* reverse1Linkedlist(Node* &head)
{
    return reverse1(head);
}
*/

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
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 5);

    InsertAtTail(tail, 15);
    InsertAtPosition(tail, head, 3, 12);

    display(head);

    // update a head
    head = reverseLinkedList(head);
    display(head);

    return 0;
}