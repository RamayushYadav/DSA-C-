// Remove all occurences of substring
#include <iostream>
#include <string>
using namespace std;

string removeOccurences(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string str;
    string parts;
    cout << "Enter the string : ";
    cin >> str;
    cout << "Enter the substring : ";
    cin >> parts;

    cout << "Output string is : " << removeOccurences(str, parts);

    return 0;
}
