// function call should be replaced by function body
#include <iostream>
using namespace std;

inline int getNum(int a, int b)
{

    // if(a > b)
    // {
    //     return a;
    // }
    // else{
    //     return b;
    // }
     
    return (a > b) ? a : b; 
}

int main()
{
    int a = 1, b = 2;
    int ans = 0;
    ans = getNum(a, b);
    cout << ans << endl;

    a = a + 3;
    b = b + 1;
    ans = getNum(a, b);
    cout << ans << endl;

    return 0;
}