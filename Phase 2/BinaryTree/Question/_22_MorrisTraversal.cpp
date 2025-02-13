// Morris Traversal
// T.C.--> O(N)
// S.C.--> O(1)
// inorder traversal
//        1
//      /   \
//     2     3
//    / \     \
//   4   5     6
//   \
//    7
// output = 4 7 2 5 1 3 6
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
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the left node of " << data << endl;
    root->left = BuildBinaryTree(root->left);

    cout << "Enter the right node of " << data << endl;
    root->right = BuildBinaryTree(root->right);

    return root;
}

void MorrisTraversal(Node *root)
{
    // pre = predecessor
    Node *current,*pre;

    if(root == NULL)
    {
        return;
    }

    current = root;

    while(current != NULL)
    {
        if(current->left == NULL)
        {
            cout << current->data<< " ";
            current = current->right;
        }

        else
        {
            // find inorder predecessor of current
            pre = current->left;
            while(pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }

            // Make current as the right child of its inorder predecessor
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            // Revert the change make in the if part to restore the original tree i.e;
            // fix the right child of the predecessor  
            else
            {
                pre->right = NULL;
                cout << current->data<< " ";
                current = current->right;
            }
        }
    }
}

int main()
{
    Node *root = BuildBinaryTree(root);

    MorrisTraversal(root);

    return 0;
}