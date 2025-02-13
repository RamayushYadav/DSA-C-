// Is Binary Tree Heap
/*
     5                       10
    / \                     /  \
   2   3                  20    30
                         / \
                       40   60
   is Heap             Not Heap
*/
#include <iostream>
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

Node *BuildBinaryTree(Node *root)
{
    int data;
    cout << "Enter the data ";
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left Node of " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right Node of " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

// MaxHeap or MaxOrder
bool isMaxOrder(Node *root)
{
    // leaf Nodes
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    // right part null ho toh left part compare karte hai
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    // agar right part or left part dono exist karte ho
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        // isleft MaxHeap && isRight MaxHeap && isroot MaxHeap
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = countNodes(root->left) + countNodes(root->right) + 1;

    return ans;
}

bool isCBT(Node *root, int index, int count)
{
    if (root == NULL)
    {
        return true;
    }

    // 0 base indexing
    if (index >= count)
    {
        return false;
    }
    else
    {
        bool left = isCBT(root->left, 2 * index + 1, count);
        bool right = isCBT(root->right, 2 * index + 2, count);

        return (left && right);
    }
}

bool isHeap(Node *root)
{
    int index = 0;
    int totalCount = countNodes(root);

    if (isCBT(root, index, totalCount) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()

{
    Node *root = NULL;

    root = BuildBinaryTree(root);
    if (isHeap(root))
    {
        cout << "Binary Tree Is Heap" << endl;
    }
    else
    {
        cout << "Binary Tree Is Not Heap" << endl;
    }
    return 0;
}