// Merge Two Binary Search Tree
/*
       50             55
      /  \           / \
     40   60        45  65
           \       /  \
           70     35   47
*/
#include <iostream>
#include <vector>
#include<queue>
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

void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> A, vector<int> B)
{
    // answer array size is (sizeof FirstArray + sizeof SecondArray)
    vector<int> ans(A.size() + B.size());
    int i = 0, j = 0, k = 0;
    while (i < A.size() && j < B.size())
    {
        // second array ka data chota hai
        if (A[i] > B[j])
        {
            ans[k++] = B[j++];
        }
        // first array ka data chota hai
        else
        {
            ans[k++] = A[i++];
        }
    }

    // remaining elements
    while (i < A.size())
    {
        ans[k++] = A[i++];
    }

    while (j < B.size())
    {
        ans[k++] = B[j++];
    }
    return ans;
}

Node *inorderToBST(int s, int e, vector<int> &in)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    Node *root = new Node(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

Node *mergeBST(Node *root1, Node *root2)
{
    vector<int> bst1, bst2;
    // step 1 store inorder
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 merge two vector arrays
    vector<int> mergeArray = mergeArrays(bst1, bst2);

    // step 3 vector convert into bst
    return inorderToBST(0, mergeArray.size() - 1, mergeArray);
}

void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()

{
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter the element of bst 1 "<<endl;
    takeInput(root1);

    cout << "Enter the element of bst 2"<<endl;
    takeInput(root2);

    Node * root = mergeBST(root1,root2);
    levelOrderTraversal(root);
    return 0;
}