// My name is Ramayush
// converts the words in string
// yM eman si hsuyamaR
#include <iostream>
#include <string>
using namespace std;

string reverse(string st)
{
    int s = 0;
    int e = st.length() - 1;
    while (s < e)
    {

        swap(st[s++], st[e--]);
    }
    return st;
}

string Reverse(string str)
{
    int i = 0;
    string temp = "";
    while (i <= str.length())
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            temp.push_back(reverse(str[i]));
        }
        i++;
    }
    return temp;
}

int main()
{
    string s;
    cout << "Enter the string : ";
    getline(cin, s);
    cout << s;

    cout << Reverse(s);

    return 0;
}