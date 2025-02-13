// Q.(1) find the duplicate number in array

// int findDuplicate(vector<int> &arr){
//     int ans = 0;
//     for(int i = 0; i < arr.size(); i++){
//      ans = ans ^ arr[i];
//     }
//     for(int i = 0; i < arr.size(); i++){
//      ans = ans ^ i;
//     }
//     return ans;
// }

// Q.(2) find the number of occerance in array
// arr[] = {2,3,4,2,3,2}
// 2 -> 3
// 3 -> 2
// 4 -> 1
// if occerance different than return true
// else return false

// Q.(3) Find all duplicates in an array

// Q.(4) find the intersection of two array

vector<int> findarrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}