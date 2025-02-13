// MCQ's in pointer
#include <iostream>
using namespace std;

int main()
{

    // // first mcq
    // int first  =  8;
    // int second = 18;
    // int *ptr = &second;
    // *ptr = 9;
    // cout << "First " << first << "  " << "Second " << second << endl;
    // // Output --> 8 9

    // // second mcq
    // int first = 6;
    // int *p = &first;
    // int *q = p;
    // (*q)++;
    // cout << *q << endl;
    // // Output --> 7

    // // Third mcq
    // int first = 8;
    // int *p = &first;
    // cout << (*p)++ << endl;
    // cout << first << endl;
    // // Output --> 8 9

    // // Fourth mcq
    // int *p = 0; // null pointer
    // int first = 710;
    // *p = first;
    // cout << first << endl;
    // // Output --> seqmentation fault

    // // Fifth mcq
    // int first = 8;
    // int second = 11;
    // int *third = &second;
    // first = *third;
    // *third = *third + 2;
    // cout << "First " << first << "  " << "Second " << second << endl;
    // // Output --> 11 13

    // // Sixth mcq
    // float f = 12.5;
    // float p = 22.5;
    // int *ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout << "*ptr " << *ptr << "  " << "f " << f << "  " << "p " << p << "  " << endl;
    // // Output --> 22.5  22.5  22.5

    // // Seventh mcq
    // int arr[5];
    // int *ptr;
    // cout << sizeof(arr) << "  " <<sizeof(ptr) << endl;
    // // Output --> 20  8

    // // Eightth mcq
    // int arr[] = {11,21,32,45};
    // cout << *arr << "  " << *(arr+1) <<endl;
    // // Output --> 11 21

    // // Nineth mcq
    // int arr[6] = {11,21,32,45};
    // cout << arr << "  " << &arr  << endl;
    // // Output --> 0x61fef8  0x61fef8

    // // teenth mcq
    // int arr[6] = {21,32,56};
    // cout << (arr + 1) << endl; // first address increment + 4
    // // Output --> 0x61fefc

    // // Eleventh mcq
    // int arr[6] = {11,21,31};
    // int *p = &arr;
    // cout << p[2] << endl;
    // // Output --> 31

    // // Twelth mcq
    // int arr[8] = {11,12,13,14,15,16};
    // cout << "(arr)"  << *(arr) << "  " << *(arr + 3) << endl;
    // // Output --> 11  14

    // // Thirteenth mcq
    // int arr[8] = {11,21,4,2};
    // int *ptr = arr+1;
    // cout << *ptr << endl;
    // // Output --> ERROR (symbol table values can't be changed)

    // // Fourteenth mcq
    // char ch = 'a';
    // char *ptr = &ch;
    // ch++;
    // cout << *ptr << endl;
    // // Output --> b

    // // Fifteenth mcq
    // char arr[6] = "abcde";
    // char *ptr = &arr[0];
    // cout << *ptr << endl;
    // // Output --> abcde

    // // Sixteenth mcq
    // char arr[6] = "abcde";
    // char *ptr = &arr[0];
    // ptr++;
    // cout << *ptr << endl;
    // // Output --> bcde

    // // Seventeenth mcq
    // char str[] = "ram";
    // char *ptr = str;
    // cout << str[0] << "   " << ptr[0] << endl;
    // // Output --> r r

    // // Eigtheenth mcq
    // int first = 110;
    // int *p = &i;
    // int **p2 = &p;
    // int second = *(q++) + 9;
    // cout << first << "  " << second << endl;
    // // Output --> 111 119

    return 0;
}