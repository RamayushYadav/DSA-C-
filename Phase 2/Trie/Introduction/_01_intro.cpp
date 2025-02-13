#include <iostream>
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
    { // allocate memory for node
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        // agar word ki length zero ho gai ho toh terminal node set kar de
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption, world will be in CAPS(capital letter)
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present (is case mein aage bad jayenge)
            child = root->children[index];
        }
        else
        {
            // absent (is case main new node create karenge fir aage bad jayenge)
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion (aage wala part recursion dekh lega)
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        { // kya ending node terminal node hai
            return root->isTerminal;
        }

        // assumption, word will be in CAPS(capital letter)
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present (is case mein aage bad jayenge)
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }

        // Recursion (aage wala part recursion dekh lega)
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // Recursive function to remove a word from the trie
    bool removeUtil(TrieNode *root, string word, int depth)
    {
        // Base case: If we reach the end of the word
        if (depth == word.length())
        {
            // If the current node is a terminal node, mark it as non-terminal
            if (root->isTerminal)
            {
                root->isTerminal = false;

                // If the node doesn't have any children, it can be deleted
                for (int i = 0; i < 26; ++i)
                {
                    if (root->children[i] != nullptr)
                        return false;
                }

                delete root;
                root = nullptr;
                return true;
            }
            return false;
        }

        // If not the end of the word, recurse for the next character
        int index = word[depth] - 'A';
        if (root->children[index] != nullptr && removeUtil(root->children[index], word, depth + 1))
        {
            // After the recursive call, if the child node is empty and not a terminal node, delete it
            if (!root->isTerminal)
            {
                delete root->children[index];
                root->children[index] = nullptr;

                // If the current node doesn't have any other children, it can be deleted
                for (int i = 0; i < 26; ++i)
                {
                    if (root->children[i] != nullptr)
                        return false;
                }

                delete root;
                root = nullptr;
                return true;
            }
        }
        return false;
    }

    // Function to remove a word from the trie
    bool removeWord(string word)
    {
        return removeUtil(root, word, 0);
    }

    //

    bool prefixUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        { // kya ending node terminal node hai
            return true;
        }

        // assumption, word will be in CAPS(capital letter)
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // present (is case mein aage bad jayenge)
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }

        // Recursion (aage wala part recursion dekh lega)
        return prefixUtil(child, word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};

int main()

{
    Trie *T = new Trie();

    T->insertWord("RAMAYUSH");

    cout << "Present Or Not " << T->searchWord("RAMAYUSH") << endl;

    T->removeWord("RAMAYUSH");

    cout << "Present Or Not " << T->searchWord("RAMAYUSH") << endl;

    T->insertWord("YADAV");
    cout << "PRESENT CHECK FROM PREFIX " << T->startsWith("YA") << endl;

    return 0;
}