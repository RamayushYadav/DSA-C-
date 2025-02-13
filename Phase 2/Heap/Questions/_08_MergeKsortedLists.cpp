// Merge K Sorted Linked lists
#include <iostream>
#include <queue>
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
    tail = temp; // Update the tail pointer to point to the new node
}

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKSortedLists(vector<Node *> &listArray)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }
    // step 1:
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }
    Node *head = NULL;
    Node *tail = NULL;
    // !minHeap.empty()
    while (minHeap.size() > 0)
    {
        Node *temp = minHeap.top();
        minHeap.pop();
        if (temp->next != NULL)
        {
            minHeap.push(temp->next);
        }
        if (head == NULL)
        {
            // LL is Empty
            head = temp;
            tail = temp;
        }
        else
        {
            // insert at linked list
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
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

    // Creating some sorted linked lists
    Node *temp1 = new Node(1);
    Node *list1_head = temp1, *list1_tail = temp1;
    InsertAtTail(list1_tail, 4);
    InsertAtTail(list1_tail, 5);
    InsertAtTail(list1_tail, 8);
    display(list1_head);

    Node *temp2 = new Node(2);
    Node *list2_head = temp2, *list2_tail = temp2;
    InsertAtTail(list2_tail, 3);
    InsertAtTail(list2_tail, 7);
    display(list2_head);

    Node *temp3 = new Node(6);
    Node *list3_head = temp3, *list3_tail = temp3;
    InsertAtTail(list3_tail, 9);
    InsertAtTail(list3_tail, 10);
    display(list3_head);

    // Storing all lists in a vector
    vector<Node *> lists = {list1_head, list2_head, list3_head};

    // Merging the lists
    Node *mergedList = mergeKSortedLists(lists);

    // Displaying the merged list
    cout << "Merged List: ";
    display(mergedList);

    return 0;
}