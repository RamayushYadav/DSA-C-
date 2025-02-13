//    sum tree
//          3      
//         / \      
//        1   2      
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

pair<bool,int> isSumTreeFast(Node *root)
{
    // base case
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    // single node
    if(root->left == NULL && root->right == NULL)
    {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    
    pair<bool,int> leftAns =  isSumTreeFast(root->left);
    pair<bool,int>  rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition = root->data == (leftAns.second + rightAns.second);
    
    pair<bool,int> ans;

    if(left && right && condition)
    {
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
        // ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
} 

bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    Node *root = NULL;

    root = BuildBinaryTree(root);

    if(isSumTree(root))
    {
        cout << "SUM TREE" << endl;
    }
    else
    {
        cout << "NOT SUM TREE" << endl;
    }

    return 0;
}