// public --> we are using these data memeber in any place
// private --> only its class can access another way to access using getter/ setter method
// greedy alignment and padding
#include <iostream>
using namespace std;

class hero
{

public:
    char level;

private:
    int health;

public:
    char getlevel()
    {
        return level;
    }

    int gethealth()
    {
        return health;
    }

    void setlevel(char l)
    {
        level = l;
    }

    void sethealth(int h)
    {
        health = h;
    }
};

int main()
{
    hero h1;
    h1.sethealth(10);
    h1.level = 'A';

    cout << h1.level << endl;
    // cout << h1.health << endl; // it wil show error
    cout << h1.gethealth() << endl;
    return 0;
}