// Double Ended Queue Using STL
#include <iostream>
#include <queue>
using namespace std;

int main()

{
    deque<int> d;

    // left side se push karna
    d.push_front(12);

    // right side se push karna
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    // left side se pop karna hai(12)
    cout << d.pop_front();
    
    // right side se pop karna hai(14)
    d.pop_back();

    if (d.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is Not Empty" << endl;
    }

    return 0;
}