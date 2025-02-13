// check if two tree are identical
//          1          1
//         / \        / \
//        2   3      2   3
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
    cout << "Enter the data : ";
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the left node of " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right node of " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

bool isIdentical(Node *r1, Node *r2)
{
    // base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }
    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if (left && right && value)
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
    Node *root1 = NULL;

    root1 = BuildBinaryTree(root1);

    Node *root2 = NULL;
    root2 = BuildBinaryTree(root2);

    if (isIdentical(root1, root2))
    {
        cout << "Both Tree Are Identical" << endl;
    }
    else
    {
        cout << "Both Tree Are Not Identical" << endl;
    }
    return 0;
}