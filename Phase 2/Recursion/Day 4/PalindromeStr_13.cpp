#include <iostream>
using namespace std;

bool palindrome(string s, int i, int j)
{

    // base case
    if (i > j)
        return true;

    if (s[i] != s[j])
        return false;

    else
    {
        return palindrome(s, i + 1, j - 1);
    }
}

int main()
{
    string str = "abcba";
    bool ans = palindrome(str, 0, str.length() - 1);

    if (ans)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}