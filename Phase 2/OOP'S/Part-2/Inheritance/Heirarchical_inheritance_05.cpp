// Herirarchical inheritance --> in this there is one base and two derived class
#include <iostream>
using namespace std;

class Person
{
public:
    void Base()
    {
        cout << "Base class persons called" << endl;
    }
};

class Male : public Person
{
public:
    void Derived1()
    {
        cout << "First Derived Male called" << endl;
    }
};

class Female : public Person
{
public:
    void Derived2()
    {
        cout << "Second Derived Female called" << endl;
    }
};

int main()
{
    Male m;
    m.Base();
    m.Derived1();

    Female f;
    f.Base();
    f.Derived2();
    return 0;
}