// find the next smallest element using stack
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> NextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    // pahale hi -1 push kar do
    s.push(-1);

    // initialize ans with same size of arr
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }

        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

void display(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()

{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);

    display(v);
    vector<int> result = NextSmallerElement(v, v.size());
    display(result);
}