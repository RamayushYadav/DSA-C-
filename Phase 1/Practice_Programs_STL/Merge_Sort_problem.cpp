// a1{1,2,3,0,0,0} and a2{2,4,5} = a2{1,2,2,3,4,5}
#include <iostream>
using namespace std;

// void merge(int arr1[], int n, int arr2[], int m)
// {
//     int i = 0, j = 0, k = 0;
//     while (i < n && j < m)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             arr1[k++] = arr1[i++];
//         }
//         else if (arr2[j] < arr1[i])
//         {
//             arr1[k++] = arr2[j++];
//         }
//     }
//     // copy the remaining element of first array
//     while (i < n)
//     {
//         arr1[k++] = arr1[i++];
//     }
//     // copy the remaining element of second array
//     while (j < m)
//     {
//         arr1[k++] = arr2[j++];
//     }
// }

void merge(int arr1[], int n, int arr2[], int m)
{
    int i = 0, j = 0, k = 0;
    while (j < m)
    {
        while (i < n)
        {
            if (arr1[i] < arr2[j])
            {
                arr1[k++] = arr1[i];
            }
            else if (arr2[j] < arr1[i])
            {
                arr1[k++] = arr2[j];
            }
            i++;
        }
        j++;
    }
}

void print(int ans[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 0, 0, 0};
    int arr2[] = {2, 4, 5};

    merge(arr1, 6, arr2, 3);
    print(arr1, 6);

    return 0;
} 