// Diameter of Binary Tree O(N)
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
    cout << "Enter the data ";
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

pair<int, int> DiameterFast(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = DiameterFast(root->left);
    pair<int, int> right = DiameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    // first is a diameter and second is a height
    pair<int, int> ans;
    // diameter formula
    ans.first = max(op1, max(op2, op3));
    // height formula
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

int Diameter(Node *root)
{
    return DiameterFast(root).first;
}

int main()

{
    Node *root = NULL;
    root = BuildBinaryTree(root);

    cout << "Diameter is : " << Diameter(root) << endl;

    return 0;
}

