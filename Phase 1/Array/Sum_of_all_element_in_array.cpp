// sum of all elements in array
#include <iostream>
using namespace std;
int Sum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
int main()
{
    int size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[100];
    cout << "Enter the elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    cout << "The sum of all elements in  array is : " << sum << endl;
    cout << "The sum of all elements in  array is : " << Sum(arr, size);
    return 0;
}