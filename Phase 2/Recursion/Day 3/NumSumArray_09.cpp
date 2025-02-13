// sum of all number is an array
#include <iostream>
using namespace std;

int sumArray(int arr[], int size)
{
    // base case
    if (size == 0)
        return 0;

    if (size == 1)
    {

    cout<<"base case arr[0] is "<<arr[0]<<endl;
        return arr[0];
    }
     

    // recursive call 
    int remainningPart = sumArray(arr + 1, size - 1);
    cout<<"arr[0] is "<<arr[0]<<endl;
    int sum = arr[0] + remainningPart;
    cout<<"some is"<<sum<<endl;

    // int sum = arr[0] + sumArray(arr+1,size-1);
    
    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int) ;

    cout <<"The sum is -> " << sumArray(arr, n);

    return 0;
}