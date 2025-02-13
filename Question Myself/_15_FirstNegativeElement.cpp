#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int neg(vector<int> &arr)
{
    int temp = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            temp = arr[i];
            break;
        }

        if (arr[i] < arr[i + 1])
        {
            temp = arr[i];
            if (temp < 0)
            {
                break;
            }
        }
        else if (arr[i] > arr[i + 1])
        {
            temp = arr[i + 1];
            if (temp < 0)
                break;
        }
        else
        {
            temp = 0;
        }
    }
    arr.erase(arr.begin(), arr.end());
    if (temp >= 0)
    {
        return 0;
    }

    return temp;
}

vector<int> Negative(int arr[], int n, int k)
{
    vector<int> compare, ans;
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = i; j < k + i; j++)
        {
            compare.push_back(arr[j]);
        }
        ans.push_back(neg(compare));
    }
    return ans;
}

int main()

{
    // int arr[] = {-8, 2, 3, -6, 10};
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    // int arr[] = {-2, 20, -6, 10, 50, -3};
    int n = sizeof(arr)/sizeof(int);
    int k = 3;

    // vector<int> ans = Negative(arr,n,k);
    // for (int i = 0; i  < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    for (const auto Ans : Negative(arr, n, k))
    {
        cout << Ans << " ";
    }
    return 0;
}
