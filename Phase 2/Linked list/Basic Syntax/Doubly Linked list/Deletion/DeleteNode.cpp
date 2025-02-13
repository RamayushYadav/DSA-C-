#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

// constructor to create node
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

// destructor for free memory manually 
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};

void InsertAtHead(Node *&tail, Node *&head, int d)
{
    // empty list
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node *&tail, Node *&head, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(Node *&tail, Node *&head, int d, int position)
{
    // first insert
    if (position == 1)
    {
        InsertAtHead(tail, head, d);
        return;
    }

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
        InsertAtTail(tail, head, d);
        return;
    }

    // insert at middle
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&tail, Node *&head)
{
    // first node delete
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        // new head
        head = temp->next;
        // free memory
        temp->next = NULL;
        delete temp;
    }

    else
    {
        // middle or last node delete
        Node *prev = NULL;
        Node *curr = head;

        int count = 1;
        // traverse linked list or shift node for specific position
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        prev->next = curr->next;

        //     free memory
        curr->next = NULL;
        delete curr;

        //  home work tail ke data ko print karna jab last node delete kar rahe ho
        if(prev->next == NULL)
        {
            tail = prev;
        }
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
    // empty list
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(tail, head, 15);
    InsertAtHead(tail, head, 10);
    InsertAtHead(tail, head, 5);
    InsertAtTail(tail, head, 20);
    InsertAtTail(tail, head, 25);
    print(head);
    InsertAtPosition(tail, head, 23, 4);
    print(head);

    deleteNode(1, tail, head);
    print(head);
    deleteNode(5, tail, head);
    print(head);
    deleteNode(2, tail, head);
    print(head);

    return 0;
}
 