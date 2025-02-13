// Single inheritance --> when one class inherit one another class propties
//  is known as single inheritance
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
    void Derived()
    {
        cout << "Derived class dog called" << endl;
    }
};

int main()
{
    Dog D;
    D.Base();
    D.Derived();

    return 0;
}