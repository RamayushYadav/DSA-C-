// Merge K Sorted Arrays
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    int i;
    int j;

    node(int data, int row, int col)
    {
        this->data = data;
        this->i = row;
        this->j = col;
    }
};

// create custom comparator
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    // step 1 : Every Arrays k first element insert hai
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // step 2 :
    // (!minHeap.empty())
    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();
        // temp node (minHeap.top()) ki ith and jth value (or index)
        int i = temp->i;
        int j = temp->j;
        // insert next element of poped array
        if (j + 1 < kArrays[i].size())
        {
            node *next = new node(kArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main()

{
    // Example usage
    vector<vector<int>> kArrays = {{1, 3, 5}, {2, 4, 6}, {0, 7, 8}};
    int k = 3; // Number of arrays

    vector<int> result = mergeKSortedArrays(kArrays, k);

    cout << "Merged Array: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}