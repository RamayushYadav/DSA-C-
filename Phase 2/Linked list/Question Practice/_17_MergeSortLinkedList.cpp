// merge sort using linked list

// prefered merge sort in linked list and quick sort in arrays
// flatten a linked list
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

void InsertAtPosition(Node *&head, Node *&tail, int d, int position)
{
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

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

Node *findMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *&left, Node *&right)
{
    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    // create dummy node
    Node *ans = new Node(-1);
    Node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    // agar left wali list null nahi hui ho toh
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    // agar right wali list null nahi hui ho toh
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    // dummy node delete kar denge
    ans = ans->next;

    return ans;
}

// merge sort in linked list
Node *mergeSort(Node *&head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // step 1 : find the mid

    Node *mid = findMid(head);

    // step 2 : break list into two halves
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // step 3 : sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // step 4 : merge both halves
    Node *result = merge(left, right);

    // step 5 : return the merged list head
    return result;
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
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    InsertAtHead(head, 3);
    InsertAtHead(head, 5);
    InsertAtPosition(head, tail, 6, 4);
    InsertAtTail(tail, 4);

    display(head);

    Node *newHead = mergeSort(head);

    display(newHead);

    return 0;
}