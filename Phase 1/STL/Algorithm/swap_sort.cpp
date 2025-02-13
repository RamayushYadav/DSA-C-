#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(8);

    sort(v.begin(), v.end());
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    int a = 5;
    int b = 6;
    cout << "Before swap the value of a is : " << a << endl;
    cout << "Before swap the value of b is : " << b << endl;
    swap(a, b);
    cout << "After swap the value of a is : " << a << endl;
    cout << "After swap the value of b is : " << b << endl;
    
    return 0;
}