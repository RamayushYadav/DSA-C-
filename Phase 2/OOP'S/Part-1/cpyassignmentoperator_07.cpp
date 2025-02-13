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
 

 void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "height: " << this->height << " ,";
        cout <<"room: " << this->room << " ]";
        cout << endl << endl;
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

    // use default copy constructor
    Home home2(home1);

    home1.name[0] = 'S';
    home1.print();
    home2.print();

    // copy assignment operator home2 element are copy into home1
    home1 = home2;
    home1.print();
    home2.print();
    return 0;
}