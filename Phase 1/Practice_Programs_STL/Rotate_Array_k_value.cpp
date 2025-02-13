// Given an array, rotate the array to the right by k steps, where k is non-negative
// nums[]={1,2,3,4,5,6,7} k = 3 output nums[]={5,6,7,1,2,3,4}
// #include<iostream>
// using namespace std;

// void rotate(int nums[],int k,int n){
//     int temp[n];
// for (int i = 0; i < n; i++)
// {
//     temp[(i+k)%n] = nums[i];
// }
// nums = temp;
// }

// void print(int arr[], int n){
//     for (int  i = 0; i < n; i++)
//     {
//     cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main ()
// {
// int arr[]={1,2,3,4,5,6,7};

// print(arr,7);
// rotate(arr,2,7);
// print(arr,7);
// return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
}

void print(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    cout << "Before rotating the array --> " << endl;
    print(v);
    rotate(v, 2);
    cout << "After rotating the array --> " << endl;
    print(v);
    return 0;
}