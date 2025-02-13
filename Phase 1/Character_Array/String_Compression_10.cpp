// String Compression
// input char{"a","a","a","a","b","b","b","b","b","b","b","b","b","b","b","b","c"}
// output("a","4","b","1","2","c") ansindex is = 6
#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while (i < n)
    {
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        // yaha kab aaoge
        //  ya toh vector pura traverse kardia
        //  ya fir new/Different character encounter kia hai

        // oldChar store karlo
        chars[ansIndex++] = chars[i];
        int count = j - i;

        if (count > 1)
        {
            // converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    vector<char> ch;

    ch.push_back('a');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('b');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');
    ch.push_back('c');

    cout << "Answer Index length of the character vector is : " << compress(ch);
    return 0;
}