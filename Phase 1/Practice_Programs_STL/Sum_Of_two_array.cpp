// sum of two array
// a1[] = {1,2,3}  and a2[]={5,9} ----> sum[] = {1,8,2}
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> &sum)
{
    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i] << " ";
    }
    cout << endl;
}

vector<int> reverse(vector<int> V)
{
    int s = 0;
    int e = V.size() - 1;
    while (s < e)
    {
        swap(V[s++], V[e--]);
    }
    // print Answer
    print(V);
    return V;
}

vector<int> FindArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;

    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // first case
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // second case
    while (j >= 0)
    {
        int sum = a[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // third case
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    
    reverse(ans);
    return ans;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2;
    v2.push_back(5);
    v2.push_back(9);

    FindArraySum(v1, 3, v2, 2);
    return 0;
}