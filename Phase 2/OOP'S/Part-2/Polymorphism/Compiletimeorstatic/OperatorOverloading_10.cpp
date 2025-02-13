// operator overloading in cpp
#include <iostream>
using namespace std;

class op
{

public:
    int a;
    void operator+(op &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;

        cout << "Output " << value2 - value1 << endl;
    }

    operator()()
    {
        cout << "Hello I am Ramayush Yadav today's date is (08/01/2024) this day is my first practical of oop's" << endl;
    }
};

int main()
{
    op obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;

    // () operator overloading
    obj1();
    return 0;
}
