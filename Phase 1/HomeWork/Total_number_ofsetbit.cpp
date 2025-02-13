//  a = 2(10) b = 3(11) total number of 1 is = 3
#include <iostream>
using namespace std;

int TotalNum(int a1, int b1)
{
    int ans1 = 0, ans2 = 0, ans3;
    while (a1 != 0)
    {
        int num1 = a1 & 1;
        if (num1 == 1)
        {
            ans1 = ans1 + num1;
        }
    }
    while (b1 != 0)
    {
        int num2 = b1 & 1;
        if (num2 == 1)
        {
            ans2 = ans2 + num2;
        }
    }
    ans3 = ans1 + ans2;
    return ans3;
}

int main()
{
    int a, b;
    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of b : ";
    cin >> b;
   cout<<"The total number of 1 is : "<<TotalNum(a, b);
    return 0;
}