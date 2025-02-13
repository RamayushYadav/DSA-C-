// find Minimum element in array
// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[5] = {3, 87, 560, 90, 2};
//     int min = arr[0];
//     for (int i = 0; i < 5; i++)
//     {
//         if (min > arr[i])
//         {
//             min = arr[i];
//         }
//     }
//     cout << "The minimum element is : " << min;

//     return 0;
// }


// Find the minimum element in array using function
#include <iostream>
using namespace std;

int getMin(int num[], int n)
{
    // int min = INT32_MAX;
    // for (int i = 0; i < n; i++)
    // {
    //     if (min > num[i])
    //     {
    //         min = num[i];
    //     }
    // }
    // return min;

    // Another way
    int mini = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, num[i]);
    }
    return mini;
}
int main()
{
    int size;
    cout << "Enter the size of array";
    cin >> size;
    int num[100];
    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }
    cout << "Minimum Number : " << getMin(num, size);
    return 0;
}