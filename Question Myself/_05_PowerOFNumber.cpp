#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main()

{ 
     string s = "Let's take LeetCode contest";
      vector<string> V;
        int temp1 = 0 , temp2 = 0,Begin = 0, End = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isspace(s[i]))
            { 
                Begin = temp2 - temp1;
                V.push_back(s.substr(Begin,temp1));
                temp1 = -1;
            }
            if( i == s.size() -1)
            {
               Begin = temp2 - temp1;
                V.push_back(s.substr(Begin,temp1+1));
            }
            temp1++;
            temp2++;
        }
        for (int i = 0; i < V.size(); i++)
        {
          cout << V[i] <<  " ";
        }
        cout << endl;

        vector<string> V2;
        for(int i = 0; i < V.size(); i++)
        {
            string str = V[i];
            reverse(str.begin(), str.end());
            V2.push_back(str);
        }

         for (int i = 0; i < V.size(); i++)
        {
          cout << V2[i] <<  " ";
        }
        cout << endl;
        string ans = "";
         for(int i = 0; i < V2.size(); i++)
        {
            string str = V2[i];
            if( i != V2.size()-1)
            {
            ans = ans + str + " ";

            }
             if( i == V2.size()-1)
            {
            ans = ans + str ;

            }
        }
     cout << ans;

    return 0;
}
