
// // Continue use in swithc case
#include <iostream>
using namespace std;

int main()
{
    int num = 2;

    switch (num)
    {
    case 1:
        cout << "First";
        break;
    case 2:
        cout << "Second";
        // Switch case not considered as loop so contiue is loop control statement it can't use in switch case
        //   continue;
        break;
    case 3:
        cout << "Third";
        break;
    case 4:
        cout << "Fourth";
        break;
    default:
        cout << "This is defalult case";
    }
    return 0;
}