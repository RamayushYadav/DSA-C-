// If switch case inside the infinite loop than what should be do (hint exit())
#include <iostream>
using namespace std;

int main()
{
    int num = 2;
    while (1)
    {
        switch (num)
        {
        case 1:
            cout << "First" << endl;
            break;
        case 2:
            cout << "Second" << endl;
            break;
        default:
            cout << "This is the default case" << endl;
        }
        exit(0);
    }
    return 0;
}
