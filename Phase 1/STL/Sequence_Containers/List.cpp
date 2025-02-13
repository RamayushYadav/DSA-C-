// list is implement by using doubly linked list doubly linked list have two pointer front and rarer
// list main vector and deque ki tarah direct access possible nhi hai isme agar middle wale element ko access karna hai
// toh traverse karke jana hoga
#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> l;

    // insert element
    l.push_back(1);
    l.push_front(2);

    // initialize different ways in list and copy list
    // list<int> n(l);
    // list<int> N(5,100);
    // for(int i:n){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // size of list
    cout << "The size of list is : " << l.size() << endl;

    // erase
    l.erase(l.begin());
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}