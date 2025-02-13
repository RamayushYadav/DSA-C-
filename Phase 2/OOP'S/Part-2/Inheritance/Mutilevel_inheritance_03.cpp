// Mutlilevel inheritance --> in this level of inheritance is two or more than two
#include <iostream>
using namespace std;

class Animal
{
public:
    void Base()
    {
        cout << "Base class animal called" << endl;
    }
};

class Dog : public Animal
{
public:
    void Derived1()
    {
        cout << "first Derived class dog called" << endl;
    }
};

class GermanShepherd : public Dog
{

public:
    void Derived2()
    {
        cout << "Second Derived class GermanShepherd called" << endl;
    }
};

int main()
{
    GermanShepherd g;
    g.Base();
    g.Derived1();
    g.Derived2();

    return 0;
}