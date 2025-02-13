// Merge two sorted linked list
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

void InsertAtPosition(Node *&tail, Node *&head, int position, int d)
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

// merge two sorted linked list

Node *solve(Node *&first, Node *&second)
{

    // only one element present in the first linked list
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    // declare the pointers for first linked list two nodes
    Node *curr1 = first;
    Node *next1 = curr1->next;
    // declare the pointner for second linked list first node
    Node *curr2 = second;

    // second linked list break nahi ho isliye usko ek new node create karke point kar denge
    Node *next2 = curr2->next;
    

    // jab tak dono linked list empty na ho jaye
    while (next1 != NULL && curr2 != NULL)
    {
        // existence check karenge kya second ka node firt list ke dono node ke bich be insert ho sakta hai
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            // node ko middle me insert kar denge
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // pointers ko aage bada denge
            curr1 = curr2; // curr1 = curr1->next
            curr2 = next2;
        }
        // agar second list ka 1 node second list ke two nodes ke bich me exist na kare

        else
        {

            // phir curr1 and next1 ko aage bada denge
            curr1 = next1; // curr1 = curr1->next
            next1 = next1->next;

            // Agar first linked list empty ho gayi ho toh
            // first list ko puri second list se joint kar denge
            if (next1 == NULL)
            
            {
                next1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node *MergeTwoSorted(Node *&first, Node *&second)
{
    // if first linked list is empty
    if (first == NULL)
    {
        return second;
    }

    // if second linked list is empty
    if (second == NULL)
    {
        return first;
    }

    //  agar first list ka data less ho
    if (first->data <= second->data)
    {
        return solve(first, second);
    }

    // agar second list ka data less ho
    // second->data <= first->data
    else
    {
        return solve(second, first);
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
    // create the first linked list
    Node *node1 = new Node(3);

    Node *Head1 = node1;
    Node *Tail1 = node1;

    InsertAtHead(Head1, 1);
    InsertAtTail(Tail1, 5);

    display(Head1);

    // create the second linked list
    Node *node2 = new Node(2);

    Node *Head2 = node2;
    Node *Tail2 = node2;

    InsertAtTail(Tail2, 5);
    InsertAtPosition(Tail2, Head2, 2, 4);
    display(Head2);

    // merge the two linked list
    MergeTwoSorted(Head1,Head2);

    display(Head1);

    return 0;
}