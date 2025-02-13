// Find Kth Largest Element in Binary Search Tree
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

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}

void kthLargestUtil(Node *root, int k, int &c)
{
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == NULL || c >= k)
        return;

    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);

    // Increment count of visited nodes
    c++;

    // If c becomes k now, then this is the k'th largest
    if (c == k)
    {
        cout << "K'th largest element is "
             << root->data << endl;
        return;
    }

    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}

// Function to find k'th largest element
void kthLargest(Node *root, int k)
{
    // Initialize count of nodes visited as 0
    int c = 0;

    // Note that c is passed by reference
    kthLargestUtil(root, k, c);
}

// void solve(Node *root,int &i,int k)
// {
//     if(root == NULL || i >= k)
//     {
//         return;
//     }

//     // R
//     solve(root->right,i,k);

//     //N
//     i++;
//     if(i == k)
//     {
//         cout <<"The largest element is " <<root->data<<endl;
//         return;
//     }

//     // L
//     solve(root->left,i,k);
// }

// void kthLargestelement(Node *root,int k)
// {
//     int i = 0;
//     solve(root,i,k);
// }

int main()
{
    Node *root = NULL;

    takeInput(root);

    kthLargest(root, 3);

    return 0;
}
