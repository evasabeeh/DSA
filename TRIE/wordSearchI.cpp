// https://www.geeksforgeeks.org/problems/word-search/

class Solution
{
public:
    int n, m;
    bool find(int i, int j, vector<vector<char>> &board, string word, int ind)
    {
        if (ind == word.size())
            return true;
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '$')
            return false;
        if (board[i][j] != word[ind])
            return false;
            
        char temp = board[i][j];
        board[i][j] = '$';

        if (find(i + 1, j, board, word, ind + 1) || find(i - 1, j, board, word, ind + 1) || find(i, j + 1, board, word, ind + 1) || find(i, j - 1, board, word, ind + 1))
        return true;
        
        board[i][j] = temp;
        return false;
    }
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0] && find(i, j, board, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};