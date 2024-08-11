// https://leetcode.com/problems/n-queens/description/

class Solution
{
public:
    vector<vector<string>> ans;
    void addSol(vector<vector<int>> &board, int n)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string str = "";
            for (int j = 0; j < n; j++)
            {
                if (board[i][j])
                    str.push_back('Q');
                else
                    str.push_back('.');
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }
    bool isSafe(int row, int col, int n, vector<vector<int>> &board)
    {
        int x = row, y = col;
        while (y >= 0)                        // no need to check for col because the queens are already added checking columns in solve()
        { // check previous rows
            if (board[x][y])
                return false;

            y--;
        }

        x = row;
        y = col;
        while (x >= 0 && y >= 0)
        { // check diagnols
            if (board[x][y])
                return false;

            x--;
            y--;
        }

        x = row;
        y = col;
        while (x < n && y >= 0)
        {
            if (board[x][y])
                return false;

            x++;
            y--;
        }
        return true;
    }
    void solve(vector<vector<int>> &board, int n, int col)
    {
        if (col == n)
        {
            addSol(board, n);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, board))
            {
                board[row][col] = 1;                  // if queen can be placed
                solve(board, n, col + 1);

                // backtrack
                board[row][col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(board, n, 0);
        return ans;
    }
};