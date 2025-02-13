// deletion in linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

 //  constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor 
    ~Node()
    {
        int value = this->data;
        // (to free memory manually)
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data "<< value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d)
{

    // insert at first
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // insert at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position,Node* &head)
{
    // deletion of first node
    if(position == 1)
    {
        Node *temp  = head;
        head = head -> next;
        // free memory
        // after we delete node, first remove pointer which points to the next node
        temp -> next = NULL;
        // then delete node
        delete temp;
    }

    else
    {
        // deletion of middle or last node
        Node * curr = head;
        Node * prev = NULL;
        int count = 1;
        // jis node ko delete karna usse ek pahale ki position
        while(count < position )
        {
            prev = curr;
            curr = curr-> next;
            count++;
        }

        prev-> next = curr-> next;
        // free memory
        curr->next = NULL;
        delete curr;

        //home work tail kese display karenge jab last node delete kare
        // if(prev-> next == NULL)
        // {
        //     tail = prev;
        // }
    }
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

    insertAtHead(head, 5);
    insertAtTail(tail, 20);
    insertAtPosition(tail, head, 3, 15);
    display(head);

     deleteNode(1,head);
    return 0;
}