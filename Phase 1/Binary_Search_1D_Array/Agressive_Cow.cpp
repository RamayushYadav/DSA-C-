// // // Aggressive Cow problem
// #include <iostream>
// using namespace std;

// bool isPossible(int arr[], int n, int m, int mid)
// {
//     int cowCount = 1;
//     int lastpos = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] - lastpos >= mid)
//         {
//             cowCount++;
//             if (cowCount == m)
//             {
//                 return true;
//             }
//             lastpos = arr[i];
//         }
//     }
//     return false;
// }

// int agressiveCows(int arr[], int n, int m)
// {
//     // sort(arr.begin(), arr.end());
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }

//     int start = 0;
//     int maxi = -1;
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(maxi, arr[i]);
//     }
//     int end = maxi;
//     int ans = -1;
//     int mid = start + (end - start) / 2;
//     while (start <= end)
//     {
//         if (isPossible(arr, n, m, mid))
//         {
//             ans = mid;
//             start = mid + 1;
//         }
//         else
//         {
//              end = mid - 1; 
//         }
//         mid = start + (end - start) / 2;
//     }
//     return ans;
// }

// int main()
// {
//     int arr[] = {4, 2, 1, 3, 6};
//     cout << "The largest minimum distance is : " << agressiveCows(arr, 5, 2);
//     return 0;
// }





// // using vector to solve this problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &Stalls, int k, int mid)
{
    int Cowcount = 1;
    int lastpos = Stalls[0];
    for (int i = 0; i < Stalls.size(); i++)
    {
        if (Stalls[i] - lastpos >= mid)
        {
            Cowcount++;
            if (Cowcount == k)
            {
                return true;
            }
            lastpos = Stalls[i];
        }
    }
    return false;
}

// 'k' is the number of cow which is initialize in function call directly
int aggressiveCows(vector<int> &Stalls, int k)
{
    std::sort(Stalls.begin(), Stalls.end());
    int start = 0;
    int maxi = -1;
    for (int i = 0; i < Stalls.size(); i++)
    {
        maxi = max(maxi, Stalls[i]);
    }
    int end = maxi;
    int ans = -1;
    int mid = start + (end - start) / 2;
    cout<<mid;
    while (start <= end)
    {
        if (isPossible(Stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int main()
{
    vector<int> Stalls;
    int size;
    cout << "Enter the size of vector : ";
    cin >> size;
    int element;
    cout << "Enter the element in vector : ";
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        Stalls.push_back(element);
    }
    cout << "The minimum largest distance is : " << aggressiveCows(Stalls, 2);
    return 0;
}