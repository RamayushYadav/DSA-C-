// Implementation of map by using red-black tree or balance tree
// map ek esa data structure hota hai jisme element unique way main hote hain
// isme data key value ke form main store rahata hai
// iska matlab mana key hai love or value hai scorpio mana love scorpio ko point kar raha hai
// map all key unique hoti hai or ek key ek hi value ko point karti hai
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "Ramayush";
    m[35] = "Yadav";
    m[2] = "Indian";

    // insert in map
    m.insert({5, "Mahakal"});

    //  count function in map
    cout << "35 is present or not : " << m.count(35) << endl;
    cout << "-35 is present or not : " << m.count(-35) << endl;
    cout << endl;

    cout << "Before erase map is ->" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    // erase in map
    m.erase(35);
    cout << "After erase map is ->" << endl;
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    
    // find function will return iterator uss particular value ka jo given hai
    auto it = m.find(2);

    for (auto i = it; i != m.end(); i++)
    {
        cout << (*i).first << " ";
    }
    cout << endl;
    return 0;
}