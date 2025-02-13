// shallow copy is done by default or inbuilt copy constructor
// #include <iostream>
// #include <string>
// using namespace std;

// class Home
// {

// public:
//     int room;
//     float height;
//     char *name;

//     Home()
//     {
//         cout << "Simple constructor called " << endl;
//         name = new char[100];
//     }

//     void print()
//     {
//         cout << "name is " << this->name << endl;
//         cout << "rooms in home is " << this->room << endl;
//         cout << "height of the home " << this->height << endl;
//     }

//     int getroom()
//     {
//         return room;
//     }

//     float getheight()
//     {
//         return height;
//     }

//     void setroom(int room)
//     {
//         this->room = room;
//     }

//     void setheight(float height)
//     {
//         this->height = height;
//     }

//     void setName(char name[])
//     {
//         this->name = name;
//     }
// };

// int main()
// {

//     Home home1;
//     home1.setroom(18);
//     home1.setheight(9.4);
//     char name[10] = "Ramayush";
//     home1.setName(name);

//     home1.print();
//     // use default copy constructor
//     Home home2(home1);
//     home2.print();

//     home1.name[0] = 'S';
//     home1.print();
//     home2.print();
//     return 0;
// }

// deep copy it is done by userdefined copy constructor
#include <iostream>
#include <cstring>
using namespace std;

class Home
{

public:
    int room;
    float height;
    char *name;

    Home()
    {
        cout << "Simple constructor called " << endl;
        name = new char[100];
    }

    // Home(int room, float height)
    // {
    //     this->room = room;
    //     this->height = height;
    // }

    Home(Home &temp)
    {
        // ek naya array bana liya
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->room = temp.room;
        this->height = temp.height;
    }
 
    void print()
    {
        cout << "name is " << this->name << endl;
        cout << "rooms in home is " << this->room << endl;
        cout << "height of the home " << this->height << endl;
    }

    int getroom()
    {
        return room;
    }

    float getheight()
    {
        return height;
    }

    void setroom(int room)
    {
        this->room = room;
    }

    void setheight(float height)
    {
        this->height = height;
    }

    void setName(char name[])
    {
        this->name = name;
    }
};

int main()
{

    Home home1;
    home1.setroom(18);
    home1.setheight(9.4);
    char name[10] = "Ramayush";
    home1.setName(name);

    home1.print();
    // use default copy constructor
    Home home2(home1);
    home2.print();

    home1.name[0] = 'S';
    home1.print();
    home2.print();
    return 0;
}

// #include<iostream>
// using namespace std;

// class Hero {

//     //properties
//     private:
//     int health;

//     public:
//     char *name;
//     char level;

//     Hero() {
//         cout << "Simple constructor called" << endl;
//         name = new char[100];
//     }

//     //Paramerterised Constructor
//     Hero(int health) {
//         this -> health = health;
//     }

//     Hero(int health, char level) {
//         this -> level = level;
//         this -> health = health;
//     }

//     //copy constructor
//     Hero(Hero& temp) {

//         char *ch = new char[strlen(temp.name) + 1];
//         strcpy(ch, temp.name);
//         this->name = ch;

//         cout << "Copy constructor called" << endl;
//         this->health = temp.health;
//         this->level = temp.level;
//     }

//     void print(){
//         cout << endl;
//         cout << "[ Name: " << this->name<< " ,";
//         cout << "health: " << this->health << " ,";
//         cout <<"level: " << this->level << " ]";
//         cout << endl << endl;
//     }

//     int getHealth() {
//         return health;
//     }

//     char getLevel() {
//         return level;
//     }

//     void setHealth(int h) {
//         health = h;
//     }

//     void setLevel(char ch) {
//         level = ch;
//     }

//     void setName(char name[]) {
//         strcpy(this->name, name);
//     }

// };
// int main ()
// {
//     Hero hero1;

//     hero1.setHealth(12);
//     hero1.setLevel('D');
//     char name[7] = "Babbar";
//     hero1.setName(name);

//     hero1.print();
// }