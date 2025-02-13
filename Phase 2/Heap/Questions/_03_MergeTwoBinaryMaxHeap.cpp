// Merge Two Binary Max Heap
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // step 1 : Merge Both Arrays Into One
    vector<int> ans;

    // forEach Loop
    for (auto i : a)
    {
        ans.push_back(i);
    }

    for (auto i : b)
    {
        ans.push_back(i);
    }

    // step 2 : Build A heap using merged array
    int size = ans.size();

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ans, size, i);
    }

    return ans;
}

int main()

{
    vector<int> A;
    A.push_back(10);
    A.push_back(5);
    A.push_back(6);
    A.push_back(2);
    vector<int> B;
    B.push_back(12);
    B.push_back(7);
    B.push_back(9);

    vector<int> merged = mergeHeaps(A, B, A.size(), B.size());
    for (int i = 0; i < merged.size(); i++)
    {
        cout << merged[i] << " ";
    }
    // 12 10 9 2 5 7 6
    return 0;
}