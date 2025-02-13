// if arr[] = {2,4,6,7,1,7}
// num = 14
// two pair = 7 7

// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[6] = {2, 3, 4, 4, 5, 7};
//     int num = 8;
//     for (int i = 0; i < 6; i++)
//     {
//         for (int j = i + 1; j < 6; j++)
//         {
//             if (arr[i] + arr[j] == num)
//             {
//                 cout << arr[i] << " " << arr[j] << endl;
//             }
//         }
//     }
//     return 0;
// }

// if arr[] = {2,4,6,4,2,7}
// num = 8
// three pair = 2 4 2

#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {2, 3, 4, 4, 5, 7};
    int num = 16;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            for (int k = j + 1; k < 6; k++)
            {
                if (arr[i] + arr[j] + arr[k] == num)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                }
            }
        }
    }
    return 0;
}