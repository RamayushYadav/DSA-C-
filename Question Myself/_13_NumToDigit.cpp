#include <iostream>
#include <cmath>
using namespace std;

int digit(int a, int b)
{

    //   int noofvariable = 3;
    //   int i = 0;
    //   while(noofvariable > i)
    //   {
    //     int temp = num * pow(10,i);

    //   }
    int ans = a * 10 + b;
    return ans;
}

int main()

{
    int a = 1, b = 7;
    cout << digit(a, b) << endl;
}