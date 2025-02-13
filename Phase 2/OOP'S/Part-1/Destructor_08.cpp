// destructor --> which is destroy the object , it can't have return type

// important point
// static object destructor is called automatically
// dynamic object destructor is called manually

#include <iostream>
using namespace std;

class Home
{
public:
    Home()
    {
        cout << "Constructor is called " << endl;
    }

    ~Home()
    {
        cout << "Destructor is called " << endl;
    }
};

int main()
{
    // static
    // destructor called automatically
    // constructor called automatically

    Home h1;

    // dynamic
    Home *h2 = new Home();
    // constructor called automatically
    // destructor called manually
    delete h2;

    return 0;
}