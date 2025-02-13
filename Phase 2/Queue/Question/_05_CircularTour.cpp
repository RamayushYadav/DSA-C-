// Circular Tour
#include <iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int deficit = 0; // kami
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        // B = B + P - D 
        balance += p[i].petrol - p[i].distance;

        // agar petrol negative ho
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

// petrol = 4 6 7 4
// distance = 6 5 3 5

int main()

{
    // Declare an array of petrolPump objects
    petrolPump p[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};

    // Get the number of petrol pumps( n = 4)
    int n = sizeof(p) / sizeof(p[0]);

    // function call
    cout << tour(p, n) << endl;

    return 0;
}