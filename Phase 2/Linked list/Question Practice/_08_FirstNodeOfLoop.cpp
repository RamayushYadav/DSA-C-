// find first node of loop using floyds algorithm
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

Node *FloydsDetectLoop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

Node *getStartingNode(Node *&head)
{
    // base case(agar loop nahi ho ya empty list ho)
    if (head == NULL)
    {
        return NULL;
    }

    Node *PointOfIntersection = FloydsDetectLoop(head);
    Node *slow = head;

    while (slow != PointOfIntersection)
    {
        slow = slow->next;
        PointOfIntersection = PointOfIntersection->next;
    }

    // first node return
    return slow;
    // return PointOfIntersection;
}

int main()

{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    InsertAtHead(head, 5);
    InsertAtTail(tail, 15);
    InsertAtPosition(tail, head, 12, 3);
    // InsertAtTail(tail, 11);
    // InsertAtTail(tail, 12);
    // InsertAtTail(tail, 13);
    // InsertAtTail(tail, 14);
    // InsertAtTail(tail, 15);
    // InsertAtTail(tail, 16);

    // last node ko second se point kar denge
    tail->next = head->next;
    // tail->next = head->next->next;

    if (FloydsDetectLoop(head) != NULL)
    {
        cout << "LOOP IS PRESENT IN THE LINKED LIST" << endl;
    }

    else
    {
        cout << "LOOP IS NOT PRESENT IN THE LINKED LIST" << endl;
    }

    Node *firstNode = getStartingNode(head);

    cout << "FIRST NODE OF LOOP " << firstNode->data << endl;
    // cout << "FIRST NODE OF LOOP " << (getStartingNode(head))->data << endl;

    return 0;
}

// second way
/*
// find first node of loop using floyds algorithm
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

Node *FloydsDetectLoop(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        if (slow == fast)
        {
            return slow;
        }
        slow = slow->next;

    }

    return NULL;
}

Node *getStartingNode(Node *&head)
{
    // base case(agar loop nahi ho ya empty list ho)
    if (head == NULL)
    {
        return NULL;
    }

    Node *PointOfIntersection = FloydsDetectLoop(head);
    Node *slow = head;

    while (slow != PointOfIntersection)
    {
        slow = slow->next;
        PointOfIntersection = PointOfIntersection->next->next;
    }

    // first node return
    return slow;
    // return PointOfIntersection;
}

int main()

{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    InsertAtHead(head, 5);
    InsertAtTail(tail, 15);
    InsertAtPosition(tail, head, 12, 3);
    // InsertAtTail(tail, 11);
    // InsertAtTail(tail, 12);
    // InsertAtTail(tail, 13);
    // InsertAtTail(tail, 14);
    // InsertAtTail(tail, 15);
    // InsertAtTail(tail, 16);

    // last node ko second se point kar denge
    tail->next = head->next;
    // tail->next = head->next->next;

    if (FloydsDetectLoop(head) != NULL)
    {
        cout << "LOOP IS PRESENT IN THE LINKED LIST" << endl;
    }

    else
    {
        cout << "LOOP IS NOT PRESENT IN THE LINKED LIST" << endl;
    }

    Node *firstNode = getStartingNode(head);

    cout << "FIRST NODE OF LOOP " << firstNode->data << endl;
    // cout << "FIRST NODE OF LOOP " << (getStartingNode(head))->data << endl;

    return 0;
}
*/