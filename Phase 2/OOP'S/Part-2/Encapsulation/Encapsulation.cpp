// Encapsulation --> Wrapping up data items and memeber function
// (information hiding,data hiding)

// Fully encapsulated class --> a class which all data members are private is called fully encapsulated.

// why encapsulation?
// adv.
// 1) Data hide karne se security increase ho jayegi
// 2) if we want we can make class "Read only"
// 3) Code reusability
// 4) encapsulation --> unit testing(chize managable ho jati hai)

#include <iostream>
using namespace std;

class Student
{

    private:
    string name;
    int age;
};

int main()
{
  Student s;

  return 0;
}