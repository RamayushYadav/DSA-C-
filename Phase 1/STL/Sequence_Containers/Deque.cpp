// Deque in STL
// deque ek esa  data structure hota hai jisme front and back dono side se insertion or deletion ho sakta hai
// isme element contiuous memory allocation ke manner main nahi hote
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;
    // push in deque

    d.push_front(2);
    d.push_back(1);

    // pop front in deque
    // cout<<"Before  pop_back deque is : ";
    // for(int i:d){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // d.pop_front();
    // cout<<"After pop_front deque is : ";
    // for(int i:d){
    // cout<<i<<" ";
    // }
    // cout<<endl;

    // pop back in deque
    // cout << "Befor pop_back deque is : ";
    // for (int i : d)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // d.pop_back();
    // cout << "After pop_back deque is : ";
    // for (int i : d)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // d.at() function in deque
    cout << "Index 0 element in deque : " << d.at(0) << endl;
    cout << "Index 1st element in deque : " << d.at(1) << endl;

    cout << "Empty or not : " << d.empty() << endl;

    //  erase function in deque
    cout << "Before erase size of  deque is : " << d.size() << endl;
    // erase parameter ese pass karte hai ki kaha se kaha tak delete karna hai
    d.erase(d.begin(), d.begin() + 1);
    cout << "After erase size of  deque is : " << d.size() << endl;

    return 0;
}