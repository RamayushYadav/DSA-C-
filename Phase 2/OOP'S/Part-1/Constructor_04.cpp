// Constructor --> it is invoke when object is created, no return type
// it have same name of class
// "Most Important point" --> Jab bhi home khud ka constructor banate hai toh jo system ne
// uska constructor banaya tha wo destroy ho jata hai

#include <iostream>
using namespace std;

class Master
{
public:
    int height;
    string name;

    // default constructor
    Master()
    {
        cout << " default constructor called" << endl;
    }

    // parameterized constructor
    Master(int h)
    {
        height = h;
        cout << "The parameterized construtor is called " << height << endl;
    }

    void print()
    {
        cout << " health " << height << endl;
    }
};

class Mister
{
public:
    int height;
    string name;

    // default constructor
    Mister()
    {
        cout << " default constructor called" << endl;
    }

    // parameterized constructor
    Mister(int h)
    {
        height = h;
        cout << "The parameterized constructor is called " << height << endl;
    }

    // copy constructor (we are use & operator to save from infinite loop which photo is in my moblie)
    Mister(Mister &temp)
    {
        this->height = temp.height;
        cout << "The copy constructor is called " << height << endl;
    }
};

int main()
{
    // constructor is always called when object is created either static or dynamic object
    // static
    // Master M;
    // // dynamic
    // Master *M1 = new Master();

    // // types of constructor
    // // 1) default constructor
    // Master M;

    // // 2) Parameterized constructor
    // Master M1(10);
    // M1.print();
    // // 3) in-built copy constructor
    // Master M2(M1);
    // M2.print();

    // users create itself copy constructor (then inbuilt copy constructor is destroy)
    Mister m(20);
    Mister m1(m);
    return 0;
}
