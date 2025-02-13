// character array can't input the value in three conditions
// (i) space
// (ii) enter
// (iii) Tab
// string is the one-diemensional character array
// if string is "Ramayush" ['R','a','m','a','y','u','s','h','\0']
#include <iostream>
using namespace std;

int main()
{
    char ch[10];
    cout << "Enter your name : ";
    cin >> ch;
    ch[3] = '\0';
    cout << "The name is : " << ch << endl;
    return 0;
}