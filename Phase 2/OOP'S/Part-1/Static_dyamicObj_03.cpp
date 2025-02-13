#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    char level;

    int gethealth()
    {
        return health;
    }
    char getlevel()
    {
        return level;
    }

    void sethealth(int h)
    {
        health = h;
    }

    void setlevel(char l)
    {
        level = l;
    }
};

int main()
{
    // statically object
    Hero h1;
    h1.sethealth(100);
    h1.setlevel('A');

    cout << "health is -> " << h1.gethealth() << endl;
    cout << "level is -> " << h1.getlevel() << endl;

    // dynamically object
    // Hero *h2 = new Hero() // another syntax for create dynamic object;
    Hero *h2 = new Hero;
    h2->sethealth(101);
    h2->setlevel('B');

    cout << "health is -> " << h2->gethealth() << endl;
    cout << "level is -> " << h2->getlevel() << endl;
    // another way for dynamic object

    (*h2).sethealth(102);
    (*h2).setlevel('C');

    cout << "health is -> " << (*h2).gethealth() << endl;
    cout << "level is -> " << (*h2).getlevel() << endl;

    return 0;
}