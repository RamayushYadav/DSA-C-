//Check the tree is balanced
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
#include<iostream>
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

pair<bool,int> isBalancedFast(Node *root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);

    // first is for balance and second for height
    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second- right.second) <= 1;

    pair<bool,int> ans; 
    // calculate the height
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff)
    {
       ans.first = true;
    }

    else
    {
        ans.first = false;
    }

    return ans;

}

bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
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