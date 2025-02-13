// Continue
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cout << " HI " << endl;
        cout << " Hey " << endl;
        continue;
        cout << "Replay to karde";
    }

    // // First Question
    // for (int i = 0; i <= 5; i++)
    // {
    //     cout << i << " ";
    //     i++;
    // }

    // // Second Question
    // for (int i = 0; i <= 5; i--)
    // {
    //     cout << i << " ";
    //     i++;
    // }

    // // Third Question
    // for (int i = 0; i <= 15; i += 2)
    // {
    //     cout << i << " ";
    //     if (i & 1)
    //     {
    //         continue;
    //     }
    //     i++;
    // }

    // // Fourth Question
    // for (int i = 0; i <= 5; i++)
    // {
    //     for (int j = i; j <= 5; j++)
    //     {
    //         cout << i << " " << j << endl;
    //     }
    // }

    // // Fifth Question
    // for (int i = 0; i <= 5; i++)
    // {
    //     for (int j = i; j <= 5; j++)
    //     {
    //         if (i + j == 10)
    //         {
    //             break;
    //         }
    //         cout << i << " " << j << endl;
    //     }
    // }

    return 0;
}
