// A phrase is palindrome if, after converting all uppercase letter
//  into lower case letters and removing all alphanumeric
// characters, it reads the same forward and backward.
//  Alphanumeric character include letters and numbers.

// Example of valid palindrome "A man,a car,a canal : Panama"
// Explanation : "amanacaracanalpanama" is a valid palindrome.

#include <iostream>
#include <string>
using namespace std;

// check the validity of characters
bool valid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// uppercase string convert into lower case
char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') && (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

// normal function which check only normal string
bool checkPalindrome(string a)
{
    int s = 0;
    int e = a.length() - 1;
    while (s <= e)
    {
        if (a[s++] == a[e--])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

// speacial function which check speacial characters, non-alphanubmeric values in string
bool isPalindromeString(string s)
{
    // faltu characters hata do
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (valid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }
    // lowercase mein kardo
    for (int j = 0; j < temp.length(); j++)
    {
        temp[j] = toLowerCase(temp[j]);
    }

    // check palindrome
    return checkPalindrome(temp);
}

int main()
{
    string s;
    cout << "Enter the string name : ";
    cin >> s;
    if (isPalindromeString(s))
    {
        cout << "String is palindrome";
    }
    else
    {
        cout << "Not paindrome string";
    }

    return 0;
}
