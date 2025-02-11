// https://leetcode.com/problems/word-search-ii

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
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    void searchUtil(TrieNode *root, vector<vector<char>> &board, int i, int j, string word, vector<vector<bool>> &vis, set<string> &st)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j])
            return;

        int idx = board[i][j] - 'a';
        if (root->children[idx] == NULL)
            return;

        word.push_back(board[i][j]);
        root = root->children[idx];
        vis[i][j] = true;

        if (root->isTerminal)
            st.insert(word);

        searchUtil(root, board, i + 1, j, word, vis, st);
        searchUtil(root, board, i - 1, j, word, vis, st);
        searchUtil(root, board, i, j + 1, word, vis, st);
        searchUtil(root, board, i, j - 1, word, vis, st);
        vis[i][j] = false;

        word.pop_back();
    }
    void searchWord(vector<vector<char>> &board, int i, int j, string &word, vector<vector<bool>> &vis, set<string> &st)
    {
        int idx = board[i][j] - 'a';
        if (root->children[idx] != NULL)
            searchUtil(root, board, i, j, word, vis, st);
    }
};
class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *t = new Trie();
        for (string word : words)
            t->insertWord(word);

        set<string> st;
        string word = "";
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                t->searchWord(board, i, j, word, vis, st);
        }
        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};