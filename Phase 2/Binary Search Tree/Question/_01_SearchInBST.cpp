// Search element in Binary Search Tree
/*
             10
            /  \
           8    21
          /      \
         7        27
        /
       5
      /
     4
    /
   3
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

Node *buildBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = buildBST(root->right, d);
    }
    else
    {
        root->left = buildBST(root->left, d);
    }
    return root;
}

void InputInBST(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}

// iterative way search in BST space complexity O(Height)
bool isPresent(Node *root, int x)
{
    // base case
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (root->data > x)
    {
        // left part me
        return isPresent(root->left, x);
    }

    else
    {
        // right part me
        return isPresent(root->right, x);
    }
}

// iterative approach in space complexity O(1)
/*
   bool isPresent(Node *root,int x)
   {
       Node *temp = root;
       while(temp != NULL)
       {
            if(root->data == x)
            {
                return true;
            }

            if( x > root->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
       }
       return false;
   }
*/

int main()

{
    Node *root = NULL;

    InputInBST(root);

    if (isPresent(root, 30))
    {
        cout << "Element is Present" << endl;
    }
    else
    {
        cout << "Element is Not Present" << endl;
    }
    return 0;
}