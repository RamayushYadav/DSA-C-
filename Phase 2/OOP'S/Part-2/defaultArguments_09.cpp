// default arguments
#include <iostream>
using namespace std;

int sum(int x, int y, int z = 0, int q = 0)
{
    return (x + y + z + q);
}

int main()
{
    cout << sum(2, 3) << endl;
    cout << sum(2, 3, 4) << endl;
    cout << sum(2, 3, 4, 5) << endl;
}