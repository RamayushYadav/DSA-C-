// Diameter of Binary Tree O(N^2)
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

int Diamter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int op1 = Diamter(root->left);
    int op2 = Diamter(root->right);
    cout << "op1 " << op1 << endl;
    cout << "op2 " << op2 << endl;


    int op3 = Height(root->left) + Height(root->right) + 1;
    cout << "op3 " << op3 << endl;

    int ans = max(op1, max(op2, op3));
    return ans;
}

int main()

{
    Node *root  = NULL;
    root = BuildBinaryTree(root);
    cout << "Diameter of binary tree is " <<  Diamter(root) << endl;
    
}