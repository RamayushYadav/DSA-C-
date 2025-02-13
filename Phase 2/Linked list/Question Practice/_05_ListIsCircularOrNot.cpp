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

void InsertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        // assuming that the element is present in the list
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element is found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

bool isCircularList(Node *&head)
{
    // jab empty list ho jab
    if (head == NULL)
    {
        return true;
    }

    // second node se start karenge
    Node *temp = head->next;
    // (first condition for non circular && second for circular)
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    // circular list ho tab
    if (temp == head)
    {
        return true;
    }

    // (temp == NULL) jab non circular list ho
    return false;
}

int main()
{
    Node *tail = NULL;

    InsertNode(tail, 5, 3);

    InsertNode(tail, 3, 5);

    InsertNode(tail, 5, 9);

    InsertNode(tail, 5, 7);

    if (isCircularList(tail))
    {
        cout << "The linked list is circular in nature" << endl;
    }

    else
    {
        cout << "The linked list is not circular in nature" << endl;
    }

    return 0;
}