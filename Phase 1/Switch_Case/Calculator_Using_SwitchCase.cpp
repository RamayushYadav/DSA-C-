// Calculator using switch case
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of b : ";
    cin >> b;
    char operation;
    cout << "Enter the operation : ";
    cin >> operation;

    switch (operation)
    {
    case '+':
        cout << "The sum is : " << (a + b);
        break;
    case '-':
        cout << "The sub is : " << (a - b);
        break;
    case '*':
        cout << "The mult is : " << (a * b);
        break;
    case '/':
        cout << "The division is : " << (a / b);
        break;
    case '%':
        cout << "The modulation is : " << (a % b);
        break;
    default:
        cout << "The operation is not valid" << endl;
    }
    return 0;
}