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

bool DetectLoop(Node *&head)
{
    // empty list
    if (head == NULL)
    {
        return false;
    }

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        // cycle is present
        if (visited[temp] == true)
        {
            cout << "LOOP IS PRESENT ON ELEMENT " << temp->data << endl;
            return true;
        }

        // true store karte jana hai map mai
        visited[temp] = true;
        temp = temp->next;
    }

    // cycle is not present
    return false;
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

    if (DetectLoop(head))
    {
        cout << "LOOP IS PRESENT IN THE LINKED LIST" << endl;
    }

    else
    {
        cout << "LOOP IS NOT PRESENT IN THE LINKED LIST" << endl;
    }
    return 0;
}