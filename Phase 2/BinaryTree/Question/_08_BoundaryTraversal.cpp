// Boundary Traversal
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
// output =  1 2 4 5 6 3
#include <iostream>
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

void traverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    // store the node
    ans.push_back(root->data);
    // left main jana hai
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }

    else
    { // right main jana hai
        traverseLeft(root->right, ans);
    }
}

void traverseLeafNode(Node *root, vector<int> &ans)
{
    // agar root null ho
    if (root == NULL)
    {
        return;
    }

    // for leaf node
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // left part
    traverseLeafNode(root->left, ans);

    // right part
    traverseLeafNode(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    // root hi null ho
    if (root == NULL)
    {
        return;
    }

    // leaf node case
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    // right traverse
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    // left traverse
    else
    {
        traverseRight(root->left, ans);
    }

    // reverse way me store kar lo
    // piche jaate jao store karte jao
    ans.push_back(root->data);
}

vector<int> Boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // root ko store karna hai
    ans.push_back(root->data);

    // left part store
    traverseLeft(root->left, ans);

    // leaf node store karo
    // left subtree
    traverseLeafNode(root->left, ans);

    // right subtree
    traverseLeafNode(root->right, ans);

    // right part store karo reverse way main
    traverseRight(root->right, ans);

    return ans;
}

int main()

{
    Node *root = NULL;
    root = BuildBinaryTree(root);

    vector<int> bdTraverse = Boundary(root);
    for (int i = 0; i < bdTraverse.size(); i++)
    {
        cout << bdTraverse[i] << " ";
    }

    return 0;
}