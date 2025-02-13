#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main ()
{
vector<int> v;
v.push_back(5);    
v.push_back(4);    
v.push_back(9);    
v.push_back(1);

cout<<"lower bound index -> "<<lower_bound(v.begin(),v.end(),9) - v.begin()<<endl;
cout<<"lower bound index -> "<<lower_bound(v.begin(),v.end(),10) - v.begin()<<endl;
cout<<endl;
cout<<"upper bound index -> "<<upper_bound(v.begin(),v.end(),9) - v.begin()<<endl;
cout<<"upper bound index -> "<<upper_bound(v.begin(),v.end(),10) - v.begin()<<endl;

return 0;
}