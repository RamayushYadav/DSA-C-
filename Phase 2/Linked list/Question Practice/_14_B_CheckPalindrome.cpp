// second approach
// middle element of the list reverse middle->next
// then compare (head to middle) == or != (middle->next to tail)
// again reverse the middle->next two can't change the list(can't manipulate the list)
// return true or false
#include <iostream>
#include <vector>
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

// check the palindrome
class Solution
{
private:
    Node *getMid(Node *&head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    Node *reverselist(Node *&head)
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

public:
    bool isPalindrome(Node *&head)
    {
        // single node present
        if (head->next == NULL)
        {
            return true;
        }

        // step 1 find the middle
        Node *middle = getMid(head);

        // step 2 reverse the linked list after the middle
        Node *temp = middle->next;
        middle->next = reverselist(temp);

        // step 3 compare both halves
        Node *head1 = head;
        Node *head2 = middle->next;
        while (head2 != NULL)
        {
            // agar equal ho toh aage bada denge
            if (head1->data == head2->data)
            {
                head1 = head1->next;
                head2 = head2->next;
            }

            else
            {
                return false;
            }
        }

        // step 4 repeat step 2
        temp = middle->next;
        middle->next = reverselist(temp);

        // step 5 returning step
        return true;
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
    // insert at head
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

    // insert at tail
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // insert at middle position
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
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;

    InsertAtHead(head, 1);
    InsertAtTail(tail, 1);
    InsertAtPosition(head, tail, 2, 3);

    display(head);

    Solution s2;

    if (s2.isPalindrome(head))
    {
        cout << "The Linked List is Palindrome" << endl;
    }
    else
    {
        cout << "The Linked List is not Palindrome" << endl;
    }

    return 0;
}