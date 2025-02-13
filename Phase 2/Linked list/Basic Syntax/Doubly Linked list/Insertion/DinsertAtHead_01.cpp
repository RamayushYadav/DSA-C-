// insertion at Head
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    // fixed pointers
    temp->next = head;
    head->prev = temp;
    // fixed head at rigth position
    head = temp;
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
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);
    InsertAtHead(head, 5);
    print(head);
    return 0;
}