// check the linked list in palindorme  or not
// copy the elements of linked list in an array approach
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
    bool checkPalindrome(vector<int> arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            if (arr[s] == arr[e])
            {
                s++;
                e--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isPalindrome(Node *&head)
    {
        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);
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

    Solution s1;

    if (s1.isPalindrome(head))
    {
        cout << "The Linked List is Palindrome" << endl;
    }
    else
    {
        cout << "The Linked List is not Palindrome" << endl;
    }
    return 0;
}