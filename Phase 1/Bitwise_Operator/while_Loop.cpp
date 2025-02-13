// Find the Product and sum of the digit
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int prod = 1;
    int sum = 0;
    while (n != 0)
    {
        int digit = n % 10;
        prod = prod * digit;
        sum = sum + digit;
        n = n / 10;
    }
    int answer = prod - sum;
    cout << "answer : " << answer;
    return 0;
}

// Dry Run 
// n  = 12345
// sum = 0;
// prod = 1;

// first while(12345 % 10 != 0){
// digit = 12345 % 10 = 5
// prod = 1 * 5 = 5
// sum = 0 + 5 = 5
// 12345/ 10 = 1234
// }

// second while(1234 % 10 != 0){
// digit = 1234 % 10 = 4
// prod = 5 * 4 = 20
// sum = 5 + 4 = 9
// 1234/ 10 = 123
// }

// third while(123 % 10 != 0){
// digit = 123 % 10 = 3
// prod = 20 * 3 = 60
// sum = 9 + 3 = 12
// 123/ 10 = 12
// }

// fourth while(12 % 10 != 0){
// digit = 12 % 10 = 2
// prod = 60 * 2 = 120
// sum = 12 + 2 = 14
// 12/ 10 = 1
// }

// fifth while(1 % 10 != 0){
// digit = 12345 % 10 = 5
// prod = 120 * 1 = 120
// sum = 14 + 1 = 15
// 1/10 = 0
// }

// answer = prod - sum = 120 - 15 = 105