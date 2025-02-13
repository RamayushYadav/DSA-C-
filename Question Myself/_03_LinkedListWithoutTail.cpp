
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *CreateNode(int data)
{
    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;

    return ptr;
}

void insertAtHead(Node *&head, int d)
{
    Node *ptr = CreateNode(d);

    ptr->next = head;
    head = ptr;
}

void insertAtTail(Node *&head, int d)
{
    Node *ptr = CreateNode(d);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

Node *lastNode(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void insertAtPosition(Node *&head, int d, int pos)
{
    Node *prev = head;
    int count = 1;
    while (count < pos - 1)
    {
        prev = prev->next;
    }
    Node *nodetoinsert = CreateNode(d);

    nodetoinsert->next = prev->next;
    prev->next = nodetoinsert;
}

void deleteHead(Node *&head)
{
    Node *ptr = head;
    head = head->next;
    delete ptr;
}

void deleteTail(Node *&head)
{
    // Node *ptr = head;
    // while (ptr->next->next != NULL)
    // {
    //     ptr = ptr->next;
    // }
    // ptr->next = NULL;
    Node *prev = NULL;
    Node *curr = head;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
}

void deleteAtPosition(Node *head, int pos)
{
    Node *p = NULL;
    Node *q = head;

    int count = 1;
    while (count < pos - 1)
    {
        p = q;
        q = q->next;
        count++;
    }

    p->next = q->next;
    q->next = NULL;
    delete q;
}

int main()
{
    Node *head = CreateNode(10);

    insertAtHead(head, 5);
    display(head);
    insertAtTail(head, 15);
    display(head);
    insertAtTail(head, 25);
    display(head);
    insertAtPosition(head, 23, 2);
    display(head);
    deleteHead(head);
    display(head);
    deleteTail(head);
    // cout<<"head->data is "<<head->data<<endl;
    display(head);
    deleteAtPosition(head, 2);
    display(head);
    deleteTail(head);
    display(head);

    // while (true)
    // {
    //     int ch;
    //     cout << " Enter 1 for InsertAtHead\n Enter 2 for InsertAtTail\n Enter 3 for InsertAtPosition\n Enter 4 for DeleteAtHead\n Enter 5 for DeleteAtTail\n Enter 6 for DeleteAtPosition\n press 8 for exit the loop\n";
    //     cin >> ch;
    //     //   int data;
    //     switch (ch)
    //     {
    //     case 1:
    //         int d1;
    //         cout << "Enter the data ";
    //         cin >> d1;
    //         insertAtHead(head, d1);
    //         display(head);
    //         break;

    //     case 2:
    //         int d2;
    //         cout << "Enter the data ";
    //         cin >> d2;
    //         insertAtTail(head, d2);
    //         display(head);
    //         break;
    //     case 3:
    //         int d3;
    //         cout << "Enter the data ";
    //         cin >> d3;
    //         int p1;
    //         cout << "Enter the positon ";
    //         cin >> p1;
    //         insertAtPosition(head, d3, p1);
    //         display(head);
    //         break;

    //     case 4:
    //         deleteHead(head);
    //         display(head);
    //         break;

    //     case 5:
    //         deleteTail(head);
    //         display(head);
    //         break;

    //     case 6:
    //         int p2;
    //         cout << "Enter the positon ";
    //         cin >> p2;
    //         deleteAtPosition(head, p2);
    //         display(head);
    //         break;

    //     case 7:
    //         display(head);

    //         break;
    //     case 8:
    //         exit(1);
    //         break;

    //     default:
    //         cout << "Chodu Bhagat Sahi Number Dal" << endl;
    //         break;
    //     }
    // }

    cout << lastNode(head)->data << endl;
    return 0;
}
