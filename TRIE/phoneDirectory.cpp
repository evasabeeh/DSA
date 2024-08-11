// https://www.geeksforgeeks.org/problems/phone-directory4628/1

class TrieNode
{
public:
    char data;
    bool isTerminal;
    TrieNode *children[26];

    TrieNode(char c)
    {
        data = c;
        isTerminal = false;
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
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a';
        TrieNode *child;

        if (root->children[idx] != NULL)
            child = root->children[idx];
        else
        {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }
    void printAll(TrieNode *curr, string str, vector<string> &temp)
    {
        if (curr->isTerminal)
        {
            temp.push_back(str);
        }
        for (char c = 'a'; c <= 'z'; c++)                 // whatever suggestions possible through this node
        {
            TrieNode *next = curr->children[c - 'a'];
            if (next != NULL)
            {
                str.push_back(c);
                printAll(next, str, temp);                  // recursion
                str.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string &word)
    {
        vector<vector<string>> ans;
        TrieNode *prev = root;

        string prefix = "";
        int i = 0;
        for (; i < word.size(); i++)       // traverse each char
        {
            char c = word[i];
            prefix.push_back(c);
            TrieNode *curr = prev->children[c - 'a'];          // find suggestions ahead of this char

            if (curr == NULL)
            {
                ans.push_back({"0"});
                break;
            }

            vector<string> temp;
            printAll(curr, prefix, temp);                   // to print all curr suggestions

            ans.push_back(temp);

            prev = curr;
        }
        while (ans.size() < word.size())
        {
            ans.push_back({"0"});
        }
        return ans;
    }
};