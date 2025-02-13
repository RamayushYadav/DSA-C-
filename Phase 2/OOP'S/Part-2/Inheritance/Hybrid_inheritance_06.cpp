// Hybrid inheritance --> in this there is the combination of two or more than two inheritance
// example multiple and heirarchical inheritance combination
#include <iostream>
using namespace std;

class CS
{
public:
    void Base1()
    {
        cout << "Base1 called" << endl;
    }
};
// heirachical
class DATASCIENTICE : public CS
{
public:
    void Derived1()
    {
        cout << "Derived1 called" << endl;
    }
};

class AI : public CS
{
public:
    void Derived2A()
    {
        cout << "Derived2A called" << endl;
    }
};

// mutliple
class IT
{
public:
    void Base2()
    {
        cout << "Base2 called" << endl;
    }
};

class WEBTECHNOLOGY : public IT, public CS
{
public:
    void Derived2B()
    {
        cout << "Derived2B called" << endl;
    }
};

int main()

{
    // herirachical
    DATASCIENTICE d;
    d.Derived1();
    d.Base1();

    AI a;
    a.Derived2A();
    a.Base1();

    // multiple
    WEBTECHNOLOGY WB;
    WB.Derived2B();
    WB.Base1();
    WB.Base2();

    return 0;
}
