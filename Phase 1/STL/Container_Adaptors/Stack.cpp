// Stack is that type of data structure in STL which is work on the principal of lifo (last in first out)
#include<iostream>
#include<stack>
using namespace std;

int main ()
{
stack<string> s;
s.push("Ramayush");
s.push("Yadav");
s.push("Indian");
cout<<"The top most element of stack is : "<<s.top()<<endl;    

s.pop();

cout<<"The top most element of stack is : "<<s.top()<<endl;    

cout<<"The size of the stack is : "<<s.size()<<endl;
cout<<"If stack is empty or not : "<<s.empty()<<endl;

return 0;
}