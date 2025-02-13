#include <iostream>
using namespace std;

void update(int arr[], int n)
{
    cout << "Inside the function" << endl;
    arr[0] = 120;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Going back to the main function" << endl;
}

int main()
{
    int arr[3] = {1, 2, 3};
    // the values are update in main function because array pass in the function through the "address"(arr)
    update(arr, 3);
    cout << "Printing the array inside the main function" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}