// Painters Partition Problmes
#include <iostream>
using namespace std;

int ispos(int a[], int n, int k, int mid)
{
    int paintercount = 1;
    int painsum = 0;
    for (int i = 0; i < n; i++)
    {

        if (painsum + a[i] <= mid)
        {
            painsum = painsum + a[i];
        }
        else
        {
            paintercount++;
            if (paintercount > k || a[i] > mid)
            {
                return false;
            }
            painsum = a[i];
        }
    }
    return true;
}

int painterspartition(int a[], int n, int k)
{
    int s = 0;
    int sum = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (ispos(a, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {5, 5, 5, 5};
    cout << "The partition of painters is : " << painterspartition(arr, 4, 2);
    return 0;
}
