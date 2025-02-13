// Check if tree is balanced or not
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
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

int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = Height(root->left);
    int right = Height(root->right);

    int ans = max(left, right) + 1;

    return ans;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int left = isBalanced(root->left);
    int right = isBalanced(root->right);

    bool diff = abs(Height(root->left) - Height(root->right)) <= 1;

    if (left && right && diff)
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
    if(isBalanced(root))
    {
        cout << "The Tree Is Balanced" << endl;
    }
    else
    {
        cout << "The Tree Is Not Balanced" << endl;
    }
    return 0;
} 