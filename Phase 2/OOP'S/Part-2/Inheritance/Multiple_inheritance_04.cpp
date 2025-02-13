// Multiple inheritance --> in this two base class and one derived class are implemented
#include <iostream>
using namespace std;

class Man
{

public:
    void Base1()
    {
        cout << "First Base class Man called" << endl;
    }
};

class Woman
{
public:
    void Base2()
    {
        cout << "Second Base class Woman called" << endl;
    }
};

class People : public Man, public Woman
{
public:
    void Derived()
    {
        cout << "Derived class both man/woman called" << endl;
    }
};

int main()
{
    People p;
    p.Base1();
    p.Base2();
    p.Derived();
    return 0;
}