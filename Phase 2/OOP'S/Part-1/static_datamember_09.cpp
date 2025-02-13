// it is a data member which is also access without creating object
// #include <iostream>
// using namespace std;

// class home
// {
//     public:
//     static int timeToComplete;
// };

// int home ::timeToComplete = 290;

// int main()
// {
//     cout << home::timeToComplete << endl;
//     home a;
//     cout << a.timeToComplete << endl;
//     return 0;
// }

// static member function
#include <iostream>
using namespace std;

class home
{
    public:
    static int timeToComplete;

    static int random(){
        return timeToComplete;
    }
};

int home ::timeToComplete = 290;

int main()
{
    cout << home::random() << endl;
 
    return 0;
}