#include <iostream>
#include <vector>
using namespace std;

void Vecprint(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    arr.erase(arr.begin(), arr.end());
    cout << endl;
}

void slidingwindow(int arr[], int n, int k)
{
    vector<int> ans;
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = i; j < k + i; j++)
        {
            ans.push_back(arr[j]);
        }
        Vecprint(ans);
    }
}

int main()

{
    int arr[] = {1, 2, 3, 10, 50, 60, 70, 90};
    int k = 4;
    int n = 8;
    slidingwindow(arr, n, k);
    return 0;
}