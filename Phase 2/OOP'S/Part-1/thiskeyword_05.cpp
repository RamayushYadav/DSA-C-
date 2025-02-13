// this keywords --> which store the address of current object
// sometimes hum class ki method ko jo parameter pass karte hai vo parameter ka name class
// ke variable ke name ke jesa hota hai toh ***this pointer*** identify karta hai class main
// joh variable create kiye hai unke address ko point karta hai

#include <iostream>
using namespace std;

class Master
{
public:
    int height;

    // use of this pointer
    Master(int height)
    {
        cout << "this-> "<< this << endl;
        this->height = height;
        cout << height << endl;
    }
};

int main()
{
    // static
    Master M(10);
    // dynamic
 cout <<"The address of currentt object " << &M << endl;
    return 0;
}