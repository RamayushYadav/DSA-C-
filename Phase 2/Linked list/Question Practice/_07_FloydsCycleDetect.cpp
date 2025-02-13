// Floyd's Cycle Detection Algorithm
// LOOP is present in the linked list or not
#include <iostream>
#include <map>
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

Node *FloydsDetectLoop(Node *&head)
{
    // empty list
    if (head == NULL)
    {
        return NULL;
    }

    // slow or fast ko head se point karenge
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
        }

        // cycle is present
        if (slow == fast)
        {
            cout << "CYCLE PRESENT AT " << slow->data << endl;
            // cout << "CYCLE PRESENT AT " << fast->data << endl;
            return slow;
            // or return fast (because they are pointing a same node);
        }

        slow = slow->next;
    }
    // cycle is not present
    return NULL;
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

    // last node ko second se point kar denge
    tail->next = head->next;
    if (FloydsDetectLoop(head) != NULL)
    {
        cout << "LOOP IS PRESENT IN THE LINKED LIST" << endl;
    }

    else
    {
        cout << "LOOP IS NOT PRESENT IN THE LINKED LIST" << endl;
    }
    return 0;
}