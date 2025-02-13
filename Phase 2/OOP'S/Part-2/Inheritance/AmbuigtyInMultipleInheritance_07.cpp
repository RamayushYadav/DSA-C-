// it is solved by '::' scope resolution operator
#include <iostream>
using namespace std;

class A
{
public:
    void Hello()
    {
        cout << "Say Hello By class A" << endl;
    }
};

class B
{
public:
    void Hello()
    {
        cout << "Say Hello By class B" << endl;
    }
};

class C : public A, public B
{
    public:
};

int main()
{
    C obj;
    // ambuigty
    // obj.Hello();

    obj.A::Hello();
    obj.B::Hello();

    return 0;
}