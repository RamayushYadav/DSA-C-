// Inheritance --> When one class properties are in the other class this concept is known as
// inheritance.

// public : --> this member is used inside and outside the parent and child class 
// private : --> only those class access this data member in which this data member should be created
// protected : --> this similar to private but one difference is that it used inside the child class
// but not used outside the child class (in main function protected member can't be intialized)


// modes of inheritance

// mode        public       protected      private

// public      public       protected      private

// protected   protected    protected      private

// private     Non          Non            Non
//             accessible   accessible     accessible

#include <iostream>
using namespace std;

class Human
{
public:
    int height;
    int weight;
    int age;

    int getAge()
    {
        return this->age;
    }

    void setHeight(int h)
    {
        this->height = h;
    }
};

class Male : public Human
{

public:
    string color;

    void sleep()
    {
        cout << "I want to sleep because temprature is very low around me (06/01/2024)" << endl;
    }
};

int main()
{

    Male object1;
    cout << object1.age << endl;
    cout << object1.height << endl;
    cout << object1.weight << endl;

    cout << object1.color << endl;
    object1.sleep();
    object1.setHeight(7);
    cout << object1.height << endl;
    return 0;
}
