// Implement A Phone Directory
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++)
        {
            char lastchar = str[i];

            prefix.push_back(lastchar);

            // check for last character
            TrieNode *curr = prev->children[lastchar - 'a'];

            // if not found
            if (curr == NULL)
            { 
                break;
            }

            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            // prefix.pop_back();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &querystr)
{
    // creationg of Trie
    Trie *t = new Trie();

    // insert all contact in trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }

    // return answer
    return t->getSuggestions(querystr);
}

int main()
{
    // Sample list of contacts
    vector<string> contactList = {"John", "Johnny", "Jane", "Jack", "James", "Jim", "Joan", "Jasper"};

    // Query string
    string querystr = "Ja";

    // Get suggestions from phone directory
    vector<vector<string>> suggestions = phoneDirectory(contactList, querystr);

    // Display suggestions
    cout << "Suggestions for prefix '" << querystr << "':" << endl;
    for (int i = 0; i < suggestions.size(); ++i)
    {
        cout << "Suggestions for position " << (i + 1) << ":" << endl;
        for (const string &suggestion : suggestions[i])
        {
            cout << suggestion << endl;
        }
    }

    return 0;
}