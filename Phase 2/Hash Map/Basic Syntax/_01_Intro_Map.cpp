// Introduction of Map
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()

{
    // Creation
    unordered_map<string, int> m;

    //**********Insertion***************

    // first way
    pair<string, int> p1 = make_pair("Ramayush", 1);
    m.insert(p1);

    // second way
    pair<string, int> p2("Brand", 1);
    m.insert(p2);

    // third way
    m["Yadav"] = 2;

    // what will happen
    m["Yadav"] = 3;

    //***********Searching**************

    cout << m["Yadav"] << endl;

    cout << m.at("Brand") << endl;

    // unknown key case
    // cout << m.at("unknownKey")<<endl; // error

    cout << m["unknownKey"] << endl; // by default zero (0)

    /*
    cout << m["unknownKey"] <<endl; // 0 value de dega key ko
    cout << m.at("unknownKey")<<endl; // 0 value pahale hi assign ho gai tho zero dega
    */

    //************size of map**************
    cout << "size of map " << m.size() << endl; // "Yadav","Ramayush","Brand","unknownkey" (4)

    //*******To Check Presence Of Entry****************
    cout << "key is present or absent " << m.count("RaoSahab") << endl; // give 0 for absent

    cout << "key is present or absent " << m.count("Yadav") << endl; // give 1 for present

    //**************erase***********
    m.erase("Yadav");
    cout << "size of map " << m.size() << endl;

    //*************Traverse Map****************
    // this is unorder_map so key will print in unorder way
    // to print key in orderd way we use map
    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}