#include <iostream>
using namespace std;

void table(int n, int temp, int i)
{

    if (n < temp)
    {
        return;
    }
    if (i > 10)
    {
        temp = temp + 1;
        i = 1;
    }

    if (!(temp > n))
    {
        cout << temp << "*" << i << "=" << temp * i << endl;
    }

    table(n, temp, i + 1);
}

int main()

{
    int n;
    cout << "Enter the value of n ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    { 
        cout <<endl;
        cout << "THIS IS TABLE OF --> "<<i << endl<<endl;;

        for (int j = 1; j <= 10; j++)
        {
            cout << i << "*"<<j<<"="<<i*j<<endl;
        }
        
    }
    // table(n, 1, 1);
    return 0;
}