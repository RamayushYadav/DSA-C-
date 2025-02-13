// // find unique number in array
#include <iostream>
using namespace std;

int Unique(int *arr, int size)
// int Unique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)  
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[7] = {2, 3, 5, 4, 2, 3, 5};
    for (int i = 0; i < 7; i++)
    {
        cout << "arr[" << i << "] : " << arr[i] << endl;
    }
    cout << "Unique number is : " << Unique(arr, 7);
    return 0;
}
