// Reverse of A String Using Stack

#include <iostream>
#include <stack>
using namespace std;

int main()

{
    string str = "Ramayush";
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string ans = "";

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    cout << "The Reversed String is : " << ans << endl;

    return 0;
}