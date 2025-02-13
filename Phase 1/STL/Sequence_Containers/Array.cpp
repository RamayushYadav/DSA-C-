// STL Array in cpp
#include <iostream>
#include <array>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    cout << "Simple Array -->" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Array using STL is -->" << endl;

    array<int, 4> a = {1, 2, 3, 4};
    
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Element at 2nd Index : " << a.at(2) << endl;
    cout << "Empty or not : " << a.empty() << endl;
    cout << "First Element in array : " << a.front() << endl;
    cout << "Lasst Element in array : " << a.back() << endl;
    return 0;
}