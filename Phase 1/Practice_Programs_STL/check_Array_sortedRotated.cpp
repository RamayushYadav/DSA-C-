// check if the array are sorted and rotated
// arr[] = {3,4,5,1,2}
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();

    // (i) started with (1) because if the (i) will be (0) than condition (i-1) given (-1) value and
    //  that value is not exist in vector exception problem
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }

    // last element compare to first element
    if (nums[n - 1] > nums[0])
    {
        count++;
    }

    // if count is 0 or 1 than return true else return false
    return count <= 1;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(2);

    if (check(v))
    {
        cout << "The array is sorted and rotated";
    }
    else
    {
        cout << "The array is not sorted and rotated";
    }

    return 0;
}