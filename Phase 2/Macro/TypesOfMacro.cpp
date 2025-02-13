// Types of Macros in C++
// Macros can be classified into four types in C++:

// 1. Object-Like Macros
// 2. Function-Like Macros
// 3. Multiline Macros
// 4. Chain Macros

// 1. Object-Like Macros
// In this example, PI is defined as an object-like macro, and whenever
//  PI appears in the code,it is replaced with the value 3.14159.

/*
#include<iostream>
using namespace std;
#define PI 3.14159
int main()
{
    int r = 3;
    double area = PI * r * r;
    cout << area << endl;
    return 0;
}
*/

// 2. Function-Like Macros
// In this example, PRINT(x) is a function-like macro that takes an argument x
// and expands to a function that prints the value of x.

/*
#include <iostream>
using namespace std;

#define PRINT(x) cout << "Value is " << x << endl

int main()
{
    int n = 3;
    PRINT(n);
    return 0;
}
*/

// 3. Multiline Macros
// In this example, we have defined a multiline macro named PRINT_RECTANGLE
// that takes two parameters: width and height. The macro is used to print a
//  rectangular pattern of asterisks (‘*’).

// #include <iostream>
// using namespace std;

// #define PRINT_RECTANGLE(width, height) \
// for (int i = 0; i < height; i++)       \
// {                                      \ 
//     for (int j = 0; j < width; j++)    \
//     {                                  \
//         cout << "*";                   \
//     }                                  \
//     cout << endl;                      \
// }                                      \

// int main()
// {
//     PRINT_RECTANGLE(4, 3);
//     return 0;
// }

// 4. Chain Macro
// In this example, we will define a macro named CLERK with value 10 and another macro
// named WORKER with value CLERK. We will then use cout to see which value is printed
// using worker macro.

// #include <iostream>
// using namespace std;

// #define CLERK 10

// #define WORKER CLERK

// int main()
// {
//     cout << WORKER;
//     return 0;
// }