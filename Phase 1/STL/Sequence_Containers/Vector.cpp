// Vector is a dynamic array which is perform similar continuous memory location as static array
// but the difference is that((Vector ke size ko increase kar sakte hai lekin ek array ke size ko nhi kar sakte))
// ek vector ka size 4 hai or hume or element insert karne hai to hum is first vector ka double size ka vector banayenge
// jisme is first  vector ke sare element copy kar dega or pahale wala vector dumb ho jayega
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    //  The differenece of capacity and size inn vector
    cout << "The Capacity of vector : " << v.capacity() << endl;
    cout << "The Size of vector : " << v.size() << endl;
    // Insert the element in vector
    v.push_back(1);
    cout << "The Capacity of vector : " << v.capacity() << endl;
    cout << "The Size of vector : " << v.size() << endl;
    v.push_back(2);
    cout << "The Capacity of vector : " << v.capacity() << endl;
    cout << "The Size of vector : " << v.size() << endl;
    v.push_back(3);
    cout << "The Capacity of vector : " << v.capacity() << endl;
    cout << "The Size of vector : " << v.size() << endl;
    cout << endl;

    // The front and back element of vector
    cout << "The front element of vector : " << v.front() << endl;
    cout << "The last element of vector : " << v.back() << endl;
    cout << endl;

    // Pop back element from vector
    cout << "Before pop the size of vector is : " << v.size() << endl;
    cout << "Before pop the capactiy of vector is : " << v.capacity() << endl;
    cout << "Before pop the element in vector : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back(); /**********/

    cout << "After pop the element in vector : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "After pop the size of vector is : " << v.size() << endl;
    cout << "After pop the capacity of vector is : " << v.capacity() << endl;
    cout << endl;

    // Clear in vector
    cout<<"Before clear the size of vector : "<<v.size()<<endl;
    v.clear();
    cout<<"After clear the size of vector : "<<v.size()<<endl;
    cout<<endl; 
    
    // Initialize vector in a different ways
    vector<int> a1;
    // 5 is the size of vector and 1 is the element which are inserted all position in vector
    vector<int> a2(5, 1);
    for (int i : a2)
    {
        cout << i << " ";
    }
    cout << endl;

    // copy vector
    vector<int> a3(a2);
    for (int i : a3)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}