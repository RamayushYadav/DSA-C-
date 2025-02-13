// Find the most occurance character in string
// example = 'Ramayush' ------> 'a'
#include <iostream>
// #include <string>
using namespace std;

char GetMaxOccurance(string s)
{
    int arr[26] = {0};

    // Create an array of count character
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    // Find maximum occurance character
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}

int main()
{
    string str;
    cout << "Enter the string : ";
    cin >> str;

    cout << "Most occurance character is : " << GetMaxOccurance(str);
    return 0;
}