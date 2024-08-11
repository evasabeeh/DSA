// https://leetcode.com/problems/replace-words/description/

class TrieNode
{
public:
    char data;
    bool isTerminal;
    TrieNode *children[26]; // no. suffices ahead of that node

    TrieNode(char c)
    {
        data = c;           // node value
        isTerminal = false; // if the node is the last node
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0'); // root node started with null char
    }
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        { // word is inserted
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode *child;

        if (root->children[idx] != NULL) // the char is already there
            child = root->children[idx];
        else
        {
            child = new TrieNode(word[0]); // if not there
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1)); // one by one char is inserted
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    void searchUtil(TrieNode *root, string word, string &rep)
    {
        if (word.length() == 0)
            return;

        int idx = word[0] - 'a';
        TrieNode *child;

        if (root->children[idx] == NULL)
            return;
        else
        {
            rep.push_back((char)(idx + 'a'));               // keep building the prefix found

            if (root->children[idx]->isTerminal)            // as soon as you found terminal, stop building prefix and return
                return;
            else
                child = root->children[idx];
        }

        searchUtil(child, word.substr(1), rep);
    }
    string searchWord(string word)
    {
        string rep = "";
        searchUtil(root, word, rep);
        return rep;
    }
};


class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie *t = new Trie();
        for (string str : dictionary)           // insert all dictionary words into the tree
            t->insertWord(str);

        stringstream ss(sentence);              // extract words
        string ans = "", word;
        while (ss >> word)
        {
            string rep = t->searchWord(word);   // search first prefix found
            if (count(dictionary.begin(), dictionary.end(), rep))          // if does not exist in dictionary then add word only
                ans += " " + rep;
            else
                ans += " " + word;
        }
        return ans.substr(1);
    }
};