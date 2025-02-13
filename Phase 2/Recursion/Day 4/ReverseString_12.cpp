#include <iostream>
using namespace std;

// // using reference variable
// void reverse(string &S, int i, int j)
// {
//     cout << "call received for " << S << endl;
//     // base case
//     if (i > j)
//         return;

//     swap(S[i], S[j]);

//     i++;
//     j--;

//     // recursive calls
//     reverse(S, i, j);

// }


// using reference variable
void reverse(string &S, int i, int n)
{
    cout << "call received for " << S << endl;
    // base case
    if (i > n-i)
        return;

    swap(S[i], S[n]);

    i++;
    
    // recursive calls
    reverse(S, i, n-i);

}

int main()
{
    string str = "Ramayush";

    reverse(str, 0, str.length() - 1);
    cout << endl;
    cout << "The final output reverse string is -> " << str;
    return 0;
}