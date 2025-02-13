// using sizeof operator
#include <iostream>
using namespace std;
int main()
{
  // size of array is 10 and 40 bytes
  int a[100]={0}; // all the elements should be 0
  int arr[10] = {1, 2, 3};
  int size = sizeof(arr) / sizeof(int);
  cout << "Size of array is : " << size;
  return 0;
}