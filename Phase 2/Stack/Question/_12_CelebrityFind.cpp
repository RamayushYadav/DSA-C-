#include <iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>> &M,int a,int b, int n)
{
    if(M[a][b] == 1) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    // step 1 : push all the elements in stack
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step 2 : pop two element from stack whenever stack.size() != 1
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        // agar a , b ko janta hai toh a celebrity nahi hai b ko push kar denge
        if (knows(M,a,b,n))
        {
            s.push(b);
        }
        else
        {
            // agar b , a ko janta hai toh a celebrity nahi hai a ko push kar denge
            s.push(a);
        }
    }

    // step 3 : if single element exist in stack(means s.size() == 1) then it is potential celebrity
    // so verify it
    int candidate = s.top();

    bool rowCheck = false;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
        {
            zeroCount++;
        }
    }
    // agar row ke all elements zero hai toh
    if (zeroCount == n)
    {
        rowCheck = true;
    }

    // coloumn count check
    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
        {
            oneCount++;
        }
    }
    // agar diagonal ko remove karke every coloumn are 1
    if (oneCount == n - 1)
    {
        colCheck = true;
    }

    // verify complete all row element 0 and column element 1
    if (rowCheck == true && colCheck == true)
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

int main()

{
    vector<vector<int>> V = {{0,1,0},{0,0,0},{0,1,0}};
    int n = V.size();
    
    int ANS = celebrity(V,n);

    cout<< ANS << endl;

    return 0;
}
