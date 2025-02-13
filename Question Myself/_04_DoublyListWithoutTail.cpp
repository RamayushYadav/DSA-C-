
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *CreateNode(int data)
{
    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    return ptr;
}

void insertAtHead(Node *&head, int d)
{
    Node *ptr = CreateNode(d);
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}

void insertAtTail(Node * &head,int d)
{
    Node * ptr = CreateNode(d);
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = ptr;
    ptr->prev = curr;
}

void insertAtPosition(Node * &head,int d,int position)
{
    if(position == 1)
    {
        insertAtHead(head,d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while(count < position-1)
    {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL)
    {
        insertAtTail(head,d);
        return;
    }

    Node *nodeToInsert = CreateNode(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;

}

void deleteHead(Node * &head)
{
    Node * temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next  = NULL;
    delete temp;
}

void deleteTail(Node * &head)
{
    Node *PREV = NULL;
    Node *CURR = head;

    while(CURR->next != NULL)
    {  
        PREV = CURR;
        CURR = CURR->next;
    }

    CURR->prev = NULL;

    PREV->next = CURR->next;

    CURR->next = NULL;

    delete CURR;
}

void deleteAtPosition(Node *&head,int pos)
{
    if(pos == 1)
    {
        deleteHead(head);
        return;
    }

    else
    {
        Node *PREV = NULL;
        Node *CURR = head;
        int count = 1;
        while(count < pos)
        {
            PREV = CURR;
            CURR = CURR->next;
            count++;
        }
        
        CURR->prev = NULL;

        PREV->next = CURR->next;

        CURR->next = NULL;

        delete CURR;
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
    Node *head = CreateNode(10);

    insertAtHead(head, 5);
    display(head);
    insertAtTail(head,15);
    display(head);
    insertAtTail(head,20);
    display(head);
    insertAtPosition(head,16,4);
    display(head);
    
    deleteHead(head);
    display(head);

    deleteTail(head);
    display(head);

    deleteAtPosition(head,2);
    display(head);
    return 0;
}
