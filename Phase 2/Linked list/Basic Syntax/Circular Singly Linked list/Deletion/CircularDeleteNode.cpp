// deletion in circular linked list
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

void deleteNode(Node *&tail, int value)
{
    // list is empty
    if (tail == NULL)
    {
        cout << "Linked list is empty can't delete node form list" << endl;
        return;
    }
    else
    {
        // list is non empty

        // assuming that "value" is present in the linked list
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 node linked list
        if (curr == prev)
        {
            tail = NULL;
        }
        // >= 2 node linked list
        if (tail == curr)
        {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;
    // list is empty
    if (tail == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    // non empty
    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    InsertNode(tail, 5, 3);
    print(tail);

    InsertNode(tail, 3, 5);
    print(tail);

    InsertNode(tail, 5, 9);
    print(tail);

    InsertNode(tail, 5, 7);
    print(tail);

    // deleteNode(tail,3);  // delete first
    // deleteNode(tail,9);  // delete last
    // deleteNode(tail,5);  // delete middle
    print(tail);
    return 0;
}