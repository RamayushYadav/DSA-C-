// Reverse the given string
#include <iostream>
using namespace std;

int main()
{
    char ch[10];
    cout << "Enter the character array : ";
    cin >> ch;
    int length = 0;
    // first calculate the length
    for (int i = 0; ch[i] != '\0'; i++)
    {
        length++;
    }
    
    // then reverse the character array
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        // int temp = ch[start++];
        // ch[start++] = ch[end--];
        // ch[end--] = temp;
        swap(ch[start++], ch[end--]);
    }
    cout << "The reverse string is : " << ch;

    return 0;
}
