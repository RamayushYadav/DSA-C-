// find Maximum element in array
// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[5] = {3, 87, 560, 90, 2};
//     int max = arr[0];
//     for (int i = 0; i < 5; i++)
//     {
//         if (max < arr[i])
//         {
//             max = arr[i];
//         }
//     }
//     cout << "The maximum element is : " << max;

//     return 0;
// }



// Find the maximum element in array using function
#include <iostream>
using namespace std;

int getMax(int num[], int n)
{
    // int max = INT32_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     // if (max < num[i])
    //     // {
    //     //     max = num[i];
    //     // }
    // }
    // // return max;

    // another way
    int maxi = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, num[i]);
    }
    return maxi;
}
int main()
{
    int size;
    cout << "Enter the size of array";
    cin >> size;
    int num[100];
    cout<<"Enter the element in array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }
    cout << "Maximum Number : " << getMax(num, size);
    return 0;
}