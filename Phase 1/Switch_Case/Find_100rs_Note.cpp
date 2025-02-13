// if the number having which no. of 100rs note 50rs and 20rs and 10rs, 2rs , 1rs
#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the value of n : ";
    cin >> num;

    while (n != 0)
    {
        switch (1)
        {
        case 1:
            cout << "The 100rs of notes : " << (num / 100);
            n = n % 100;
        case 2:
            cout << "The 50rs of notes : " << (num / 50);
            n = n % 50;

        case 3:
            cout << "The 20rs of notes : " << (num / 20);
            n = n % 20;

        case 4:
            cout << "The 10rs of coins : " << (num / 10);
            n = n % 10;

        case 5:
            cout << "The 2rs of coins : " << (num / 2);
            n = n % 2;

        case 6:
            cout << "The 1rs of coins : " << (num / 1);
            n = n % 1;
        }
    }
        return 0;
    }