// check if string is palindrome or not
// if first string is upper case and second string is lower case but they are equal
//  then upper case convert into lower case
// [Special character ---> {*,?,@,#,$,&} can't be considered.]
#include <iostream>
using namespace std;

//  convert upper case into lower case
char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

// check palindrome function
bool checkpalindrome(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (toLowerCase(name[s++]) == toLowerCase(name[e--]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    char ch[10];
    cout << "Enter the string : ";
    cin >> ch;
    int length = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        length++;
    }

    if (checkpalindrome(ch, length))
    {
        cout << "The given string is palindrome" << endl;
    }

    else
    {
        cout << "The given string is not palindrome" << endl;
    }
    cout << " the lower case character -> " << toLowerCase('a') << endl;
    cout << " the upper case character -> " << toLowerCase('A') << endl;
    return 0;
}