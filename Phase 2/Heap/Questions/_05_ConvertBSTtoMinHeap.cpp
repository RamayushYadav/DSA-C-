// convert Binary Search Tree into Min Heap
/*
             4                 1
           /   \             /   \
          2     6   --->    2     5
         / \   / \         / \   / \
        1   3 5   7       3   4 6   7

*/

#include <iostream>
#include <queue>
#include <vector>
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

void inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void preOrder(Node *root, vector<int> &pre, int &index)
{
    if (root == NULL)
    {
        return;
    }

    root->data = pre[index++];

    preOrder(root->left, pre, index);
    preOrder(root->right, pre, index);
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    // push NULL as separator
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl; // enter
            if (!q.empty())
            {
                // queue still has some child
                // then again use separator
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
Node *ConvertIntoHeap(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    vector<int> in;
    inorder(root, in);
    int index = 0;
    preOrder(root, in, index);

    return root;
}

int main()

{
    Node *root = NULL;
    takeInput(root);
    root = ConvertIntoHeap(root);
    levelOrderTraversal(root);

    return 0;
}
