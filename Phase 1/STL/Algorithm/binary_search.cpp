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

    cout << "Searching element : " << binary_search(v.begin(), v.end(), 8) << endl;
    cout << "Searching element : " << binary_search(v.begin(), v.end(), -8) << endl;

    return 0;
}