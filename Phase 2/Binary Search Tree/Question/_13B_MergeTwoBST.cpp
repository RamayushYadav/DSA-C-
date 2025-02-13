// Merge Two Binary Search Tree
/*
       50             55
      /  \           / \
     40   60        45  65
           \       /  \
           70     35   47


       50
      /  \
     40   60
    / \   / \
  35  45 55  65
       \      \
       47     70
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = buildBST(root->right, d);
    }
    else
    {
        root->left = buildBST(root->left, d);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// step 1
void ConvertIntoSortDoublylist(Node *root, Node *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    ConvertIntoSortDoublylist(root->right, head);

    root->right = head;

    if (head != NULL)
    {
        head->left = root;
    }

    head = root;

    ConvertIntoSortDoublylist(root->left, head);
}

// step 2
Node *MergeLinkedList(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        // when bst1 data is less
        if (head1->data < head2->data)
        {
            // when merged list is empty
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            // if nodes are present in the list
            else
            {
                // insert at tail
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        // when bst2 data is small
        else
        {
            // when merged list is empty
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            // if nodes are present in the list
            else
            {
                // insert at tail
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    // for remaining nodes
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// count the number of nodes
int countNodes(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

// step 3
Node *sortedLinkListToBST(Node *&head, int n)
{
    // base case
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    Node *left = sortedLinkListToBST(head, n / 2);

    Node *root = head;

    root->left = left;

    head = head->right;

    root->right = sortedLinkListToBST(head, n - n / 2 - 1);

    return root;
}

Node *mergeBST(Node *root1, Node *root2)
{
    // step 1 :- convert BST into sorted DLL in_place
    Node *head1 = NULL;
    ConvertIntoSortDoublylist(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    ConvertIntoSortDoublylist(root2, head2);
    head2->left = NULL;

    // step 2 :- merge two sorted linked list
    Node *head = MergeLinkedList(head1, head2);

    // step 3 :- convert sorted linked list into binary search tree
    return sortedLinkListToBST(head, countNodes(head));
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()

{
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter the element of bst 1 " << endl;
    takeInput(root1);

    cout << "Enter the element of bst 2" << endl;
    takeInput(root2);

    Node *root = mergeBST(root1, root2);
    levelOrderTraversal(root);
    return 0;
}