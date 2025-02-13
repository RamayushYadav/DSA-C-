// how to find the length of string using character array
#include <iostream>
using namespace std;

int main()
{
    char ch[10];
    int length = 0;
    cout << "Enter the character array : ";
    cin >> ch;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        length++;
    }
    cout << "The length of string is : " << length;
    return 0;
}

// Another way to implement this program

// #include <iostream>
// #include<string>
// using namespace std;

// int main()
// {
//     string str;
//     cout << "Enter the string to find the length  : ";
//     cin >> str;
//     int length = 0;
//     while(str[length] != '\0')
//     {
//         length++;
//     }
//     cout <<"The length of string is : "<< length;
//     return 0;
// }