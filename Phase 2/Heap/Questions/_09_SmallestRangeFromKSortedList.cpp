// Smallest Range From K Sorted List
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<node *, vector<node *>, compare> minHeap;

    // step 1 : Create a minHeap for starting element of each list and tracking mini/maxi value
    for (int i = 0; i < k; i++)
    {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    // step 2:
    int start = mini, end = maxi;
    // process range
    while (!minHeap.empty())
    {
        // mini fetch
        node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;
        // range or answer updation
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // next element exists
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minHeap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            // next element does not exist
            break;
        }
    }
    // returning the difference of range
    return (end - start + 1);
}

int main()

{
    vector<vector<int>> arr = {{1, 10, 11}, {2, 3, 20}, {5, 6, 12}};
    cout << "arr.size() -> n -> " << arr.size() << endl;
    int Range = kSorted(arr, 3, arr.size());

    cout << "Range is " << Range << endl;

    return 0;
}