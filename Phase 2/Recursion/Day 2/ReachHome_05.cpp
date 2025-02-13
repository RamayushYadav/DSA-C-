// Ghar pahuchna hai(source,destination)
#include <iostream>
using namespace std;

void Reachhome(int src, int dest)
{

    cout << "source " << src << " destination " << dest << endl;

    // base case
    if (src == dest)
    {
        return;
    }
    // Processing ek step aage badh jao
    src++;

    // recursive relation
    return Reachhome(src, dest);
}

int main()
{
    int src = 1;
    int dest = 10;
    Reachhome(src, dest);

    return 0;
}