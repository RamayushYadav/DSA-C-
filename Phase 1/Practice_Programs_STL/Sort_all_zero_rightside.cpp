// if given arr[]={0,2,0,0,1,0,3} ans is arr[]={2,1,3,0,0,0,0}
#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void sortzero(int arr[], int n)
{
    // Shift all non zero values to left
    int nonZero = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            int temp = arr[j];
            arr[j] = arr[nonZero];
            arr[nonZero] = temp;
            nonZero++;
        }
    }
}

int main()
{
    int arr[] = {0, 2, 0, 0, 1, 0, 3};
    print(arr, 7);
    sortzero(arr, 7);
    print(arr, 7);
    return 0;
}