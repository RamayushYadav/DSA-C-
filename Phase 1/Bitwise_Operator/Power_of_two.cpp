// The number is power of 2
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 31; i++)
    {
        int ans = pow(2, i);
        if (ans == n)
        {
            return true;
        }
        return false;
    }
    return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < 31; i++)
//     {
//         if (ans == n)
//         {
//             return true;
//         }
//     if (ans == INT_MAX/2)
//      ans = ans * 2;
//     }
//         return false;
//     return 0;
// }