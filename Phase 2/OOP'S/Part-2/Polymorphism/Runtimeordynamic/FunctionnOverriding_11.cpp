// function overriding achived by inheritance
#include <iostream>
using namespace std;

class Parent
{
public:
    void show()
    {
        cout << "Hello I am Parent class" << endl;
    }
};

class child : public Parent
{
public:
    void show()
    {
        cout << "Hello I am child class" << endl;
    }
};

int main()
{
    child c;
    c.show();
    return 0;
}