// Top View Of Binary Tree
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
// output =  1 2 4
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
    cout << "Enter the data  ";
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

void solve(Node *root,vector<int> &ans,int level)
{
    if(root == NULL)
    {
        return;
    }

    if(level == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> LeftView(Node *root)
{
    vector<int> ans;
    solve(root,ans,0);

    return ans;
}

int main()

{
    Node *root = BuildBinaryTree(root);

    vector<int> leftView = LeftView(root);

    for (int i = 0; i < leftView.size(); i++)
    {
        cout << leftView[i] << " ";
    }
    return 0;
}
