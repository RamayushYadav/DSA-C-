/*(1)   ****      (2) 1111     (3) 1234   (4) 4321   (5) 1 2 3   (6) *         (7) 1          (8) 1
        ****          2222         1234       4321       4 5 6       * *           2 2            2 3
        ****          3333         1234       4321       7 8 9       * * *         3 3 3          4 5 6 
        ****          4444         1234       4321                   * * * *       4 4 4 4        7 8 9 10
 




 
 
  (9)   1        (10) 1       (11) A A A  (12) A B C  (13) A B C  (14) A B C    (15) A        (16) A
        2 3           2 1          B B B       A B C       D E F       B C D         B B           B C 
        3 4 5         3 2 1        C C C       A B C       G H I       C D E         C C C         D E F 
        4 5 6 7       4 3 2 1                                                                      G H I J


  (17)  A        (18) D       (19)      *  (20) * * * *  (21) * * * *  (22)  1 1 1 1    (23) 1 2 3 4         
        B C           C D             * *       * * *           * * *          2 2 2           2 3 4          
        C D E         B C D         * * *       * *               * *            3 3             3 4         
        D E F G       A B C D     * * * *       *                   *              4               4                 
  

   (24)       1    (25)     1      (26)       1      (27)  1 2 3 4 5 5 4 3 2 1    (28)     *       
            2 2           2 3               2 1 2          1 2 3 4 * * 4 3 2 1           * * *     
          3 3 3         4 5 6             3 2 1 2 3        1 2 3 * * * * 3 2 1         * * * * *                                   
        4 4 4 4       7 8 9 10          4 3 2 1 2 3 4      1 2 * * * * * * 2 1       * * * * * * *                                     
                                                           1 * * * * * * * * 1

   (29)      *           (30)       1             (31) *      *       
           * * *                  2 1 2                **    **+
         * * * * *              3 2 1 2 3              ***  ***
       * * * * * * *          4 3 2 1 2 3 4            ********
         * * * * *                                     ********
           * * *                                       ***  ***
             *                                         **    **
                                                       *      *
(32)   ********
      ****  ****
     ****    ****
    ****      ****
    ****      ****
     ****    ****
      ****  ****
       ******** 

*/
#include<iostream>
#include<string>
using namespace std;

bool palindrome(string str,int l){
  
int s = 0;
int e = l-1;
while(s < e){
  if(str[s++] ==  str[e--]){
    return 1;
  }
  return 0;
}

}

int main ()
{
string st;
cout<<"Enter the string to reverse the string -> ";
cin>>st;

int len = 0;
while(st[len] != '\0'){
  len++;
}

if(palindrome(st,len)){
  cout<<"PALINDROME";
}

else{
  cout<<"NOT PALINDROME";
}

return 0;
}