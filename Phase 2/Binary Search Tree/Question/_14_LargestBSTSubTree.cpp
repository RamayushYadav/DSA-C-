// Largest Binary Search Subtree
/*
        5
      /  \
     2    4
    / \
   1   3
*/
#include <iostream>
#include <climits>
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

Node *buildBST(Node *root)
{
    int data;
    cout << "Enter the data ";
    cin >> data;

    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node of " << root->data << " ";
    root->left = buildBST(root->left);

    cout << "Enter the right node of " << root->data << " ";
    root->right = buildBST(root->right);

    return root;
}

class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(Node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // answer update
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestSize(Node *root)
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main()

{
    Node *root = NULL;
    // takeInput(root);
    root = buildBST(root);
    int largeSize = largestSize(root);

    cout << "The large size is -> " << largeSize << endl;

    return 0;
}