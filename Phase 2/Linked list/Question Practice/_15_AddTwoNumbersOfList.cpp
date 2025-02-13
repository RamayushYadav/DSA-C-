// Add two numbers of linked lists
// 3 4 5 and 4 5 --> 3 9 0
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

class Solution
{
private:
    Node *reverse(Node *&head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *forward = NULL;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    void insertAtTail(Node *&head, Node *&tail, int value)
    {
        Node *temp = new Node(value);
        // empty list
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }

        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    Node *add(Node *&first, Node *&second)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;

        while (first != NULL && second != NULL)
        {
            int sum = carry + first->data + second->data;

            int digit = sum % 10;

            // create node and add in answer linked list
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            first = first->next;
            second = second->next;
        }

        // agar first list lenght jayada ho(matlab agar second end ho gai or first na hui ho)
        while (first != NULL)
        {
            int sum = carry + first->data;
            int digit = sum % 10;

            // create node and add in answer linked list
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first->next;
        }

        // agar second list lenght jayada ho(matlab first end ho gai or second na hui)
        while (second != NULL)
        {
            int sum = carry + second->data;
            int digit = sum % 10;

            // create node and add in answer linked list
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            second = second->next;
        }

        // agar last main carry rah gayi ho
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            // create node and add in answer linked list
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
        }

        /*
        while(first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;

            if(first != NULL)
            {
                val1 = first->data;
            }

            int val2 = 0;

            if(second != NULL)
            {
                val2 = second->data;
            }

            int sum = carry + val1 + val2;

            int digit = sum%10;
            // create node and add in answer linked list
            insertAtTail(ansHead, ansTail, digit);

            carry = sum/10;

            if(first != NULL)
            {
                first = first->next;
            }

            if(second != NULL)
            {
                second = second->next;
            }
        }
           return ansHead;

        */

        return ansHead;
    }

public:
    Node *AddTwoLists(Node *&first, Node *&second)
    {
        // step 1 - reverse the both input linked lists
        first = reverse(first);
        second = reverse(second);

        // step 2 - add both linked list
        Node *ans = add(first, second);

        // step 3 - reverse the answer linked list
        ans = reverse(ans);

        return ans;
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
    Node *node1 = new Node(4);
    Node *head1 = node1;
    Node *tail1 = node1;

    InsertAtHead(head1, 3);
    InsertAtTail(tail1, 5);

    Node *node2 = new Node(4);
    Node *head2 = node2;
    Node *tail2 = node2;

    InsertAtTail(tail2, 5);

    display(head1);
    display(head2);

    Solution s1;

    Node *resultHead = s1.AddTwoLists(head1, head2);

    display(resultHead);

    return 0;
}