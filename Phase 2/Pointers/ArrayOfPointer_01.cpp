// Array of pointer
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {23, 45, 676};

    cout << "Address of first memory block -> " << arr << endl;
    cout << "Address of first memory block -> " << &arr[0] << endl;

    cout << "Value at address of first memory block -> " << *arr << endl;
    cout << "Value at address increment -> " << *arr + 1 << endl;
    cout << "Value at address increment -> " << *(arr) + 1 << endl;
    cout << "Address increment and than give value at address -> " << *(arr + 1) << endl;
    cout << "Value at index 2 is -> " << arr[2] << endl;
    cout << "Value at index 2 is -> " << *(arr + 2) << endl;

    int i = 2;
    cout << "Value at index 2 is -> " << arr[i] << endl;
    // formula is ---> arr[i] = *(arr + i)
    // formula is ---> i[arr] = *(i + arr)
    cout << "Value at index 2 is -> " << i[arr] << endl;

    int temp[10] = {1, 2};
    cout << "sizeof all elements of array -> " << sizeof(temp) << endl;
    cout << "sizeof first value of array (integer) -> " << sizeof(*temp) << endl;
    cout << "sizeof first address of array -> " << sizeof(&temp) << endl;

    int *ptr = &temp[0];
    cout << "sizeof first memory address of array -> " << sizeof(ptr) << endl;
    cout << "sizeof first memory address value of array -> " << sizeof(*ptr) << endl;
    cout << "sizeof first memory address of array -> " << sizeof(&ptr) << endl;

    return 0;
}
