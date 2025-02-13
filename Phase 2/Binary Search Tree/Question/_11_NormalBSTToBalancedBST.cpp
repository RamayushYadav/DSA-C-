// Normal BST To Balanced BST
// A Balanced BST is defined as a BST,in which the height of two subtrees of every nodes
// differs no more than 1

/*
             50
            /  \
          20    70
         / \     \
       10  30    90
                   \
                   110
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

void inorder(Node *root, vector<int> &in)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node *inorderToBST(int s, int e, vector<int> &in)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;

    Node *root = new Node(in[mid]);

    root->left = inorderToBST(s, mid - 1, in);

    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

Node *BalancedBST(Node *root)
{
    vector<int> inorderVal;

    inorder(root, inorderVal);

    return inorderToBST(0, inorderVal.size() - 1, inorderVal);
}

void *levelOrderTraversal(Node *root)
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
    Node *root = NULL;

    takeInput(root);
    levelOrderTraversal(root);
    cout << endl;
    root = BalancedBST(root);
    levelOrderTraversal(root);
    return 0;
}