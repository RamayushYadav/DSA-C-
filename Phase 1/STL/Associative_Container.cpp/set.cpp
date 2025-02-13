// set is that type of data structure jisme all elements unique way main store hote hai
// agar humne 5 ko five times set main store kiya hai toh set only one time 5 ko store karega
// set ki implementation(BST) binary search tree ka use karke hoti hai
// colon(:) belongs to ko indicate karta hai

#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(6);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(1);
    s.insert(1);

    // for(int i: s)
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // erase element in set
    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    // count function in set
    cout << "5 is present or not : " << s.count(5) << endl;
    cout << "-5 is present or not : " << s.count(-5) << endl;

    // find functin in set(find element take reference it means jo element find hoga waha se element print hona start honge)
    set<int>::iterator itr = s.find(5);
    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
