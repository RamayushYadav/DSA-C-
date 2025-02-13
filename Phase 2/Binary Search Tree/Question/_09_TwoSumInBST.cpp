// Two Sum In Binary Search Tree
/*
             50
            /  \
          20    70
         / \     \
       10  30    90
                   \
                   110
*/
// inorder = 10 20 30 50 70 90 110
// input  target = 120,
// output 50+70 = 120  return TRUE
#include<iostream>
#include<vector>
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

Node *buildbst(Node *root,int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right = buildbst(root->right,d);
    }

    else
    {
        root->left = buildbst(root->left,d);
    }

    return root;
}

void takeinput(Node *&root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = buildbst(root,data);
        cin >> data;
    }
}

void inorder(Node *root,vector<int> &in)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    
    // L N R
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSumInBST(Node *root,int target)
{
    /// save inorder
    vector<int> inorderVal;
    // call inorder function
    inorder(root,inorderVal);
    int i = 0, j = inorderVal.size()-1;

    while(i<j)
    {
        int sum = inorderVal[i] + inorderVal[j];

        if(sum == target)
        {
            return true;
        }
        else if(sum > target)
        {
            j--;
        }
        // sum < target
        else
        {
            i++;
        }
    }

    return false;
}

int main()

{
    Node *root = NULL;

    takeinput(root);
    
    int target = 120;
    if(twoSumInBST(root,target))
    {
        cout << "TWO NUMBERS ARE PRESENT IN BST WHOSE SUM IS "<<target<<endl;
    }
    else
    {
        cout << "TWO NUMBERS ARE NOT PRESENT IN BST"<<endl;
    }

    return 0;
}