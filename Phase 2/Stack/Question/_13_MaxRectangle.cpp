// Maximum Rectangle in 2D Matrix
#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;
const int MAX = 1000;

vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        if (arr[s.top()] >= curr)
        {
            s.pop();
        }

        // stack ka top hi smaller element hai
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        if (arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(int *heights, int n)
{

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;

        area = max(area, newArea);
    }

    return area;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    // compute area for first row
    int area = largestRectangleArea(M[0], m);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row update: by adding previous rows value

            // row add tabhi karte hai jab base 0 na ho
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }

        // entire area is update know
        area = max(area, largestRectangleArea(M[i], m));
    }

    return area;
}

int main()

{
    int M[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    int maxi = maxArea(M, 4, 4);

    // cout << maximum << endl;
    return 0;
}



// #include <iostream>
// #include <stack>
// #include <vector>
// #include <limits.h>
// using namespace std;

// const int MAX = 1000;

// vector<int> nextSmallerElement(vector<int>& arr, int n)
// {
//     stack<int> s;
//     s.push(-1);

//     vector<int> ans(n);

//     for (int i = n - 1; i >= 0; i--)
//     {
//         int curr = arr[i];

//         while (!s.empty() && arr[s.top()] >= curr)
//         {
//             s.pop();
//         }

//         ans[i] = s.top();
//         s.push(i);
//     }
//     return ans;
// }

// vector<int> prevSmallerElement(vector<int>& arr, int n)
// {
//     stack<int> s;
//     s.push(-1);

//     vector<int> ans(n);

//     for (int i = 0; i < n; i++)
//     {
//         int curr = arr[i];

//         while (!s.empty() && arr[s.top()] >= curr)
//         {
//             s.pop();
//         }

//         ans[i] = s.top();
//         s.push(i);
//     }

//     return ans;
// }

// int largestRectangleArea(vector<int>& heights)
// {
//     int n = heights.size();

//     vector<int> next = nextSmallerElement(heights, n);
//     vector<int> prev = prevSmallerElement(heights, n);

//     int area = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int l = heights[i];

//         if (next[i] == -1)
//         {
//             next[i] = n;
//         }

//         int b = next[i] - prev[i] - 1;

//         int newArea = l * b;

//         area = max(area, newArea);
//     }

//     return area;
// }

// int maxArea(int M[MAX][MAX], int n, int m)
// {
//     if (n <= 0 || m <= 0)
//     {
//         return 0;
//     }

//     int area = largestRectangleArea(vector<int>(M[0], M[0] + m));

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (M[i][j] != 0)
//             {
//                 M[i][j] = M[i][j] + M[i - 1][j];
//             }
//             else
//             {
//                 M[i][j] = 0;
//             }
//         }

//         area = max(area, largestRectangleArea(vector<int>(M[i], M[i] + m)));
//     }

//     return area;
// }

// int main()
// {
//     int M[4][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

//     int maximum = maxArea(M, 4, 4);

//     cout << maximum << endl;
//     return 0;
// }
