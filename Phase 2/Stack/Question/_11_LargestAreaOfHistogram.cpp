// largest area of histogram
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        // index push karenge
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        // index push karenge
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // next smallest element
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    // previous smallest element
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // it is constant
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        // breadth
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;

        area = max(area, newArea);
    }

    return area;
}

int main()
{
    // Example usage:
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);

    cout << "Largest Rectangle Area: " << result << endl;

    return 0;
}