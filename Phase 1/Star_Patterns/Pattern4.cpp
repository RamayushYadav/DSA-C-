// Number pattern
// 4 3 2 1
// 4 3 2 1
// 4 3 2 1
// 4 3 2 1

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the value of n : ";
//     cin >> n;
//     int i = n;
//     while (i >= 1)
//     {
//         int j = n;
//         while (j >= 1)
//         {
//             cout << j << " ";
//             j--;
//         }
//         cout << endl;
//         i--;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            int num = n - j + 1;
            cout << num << " ";
            // cout<< n-j+1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}