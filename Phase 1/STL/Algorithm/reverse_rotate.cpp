#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(8);

  string  str = "abcd";
  reverse(str.begin(),str.end());
cout<<"reverse string is -> "<<str<<endl;

// rotate
rotate(v.begin(),v.begin()+1,v.end());
cout<<"After rotate -> "<<endl;
for(int i:v){
    cout<<i<<" ";
}
cout<<endl;
    return 0;
}