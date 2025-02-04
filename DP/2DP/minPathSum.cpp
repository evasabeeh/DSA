// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return INT_MAX;

        if (i == 0 && j == 0)
            return grid[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = solve(grid, i - 1, j, dp);
        int left = solve(grid, i, j - 1, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(grid, n - 1, m - 1, dp);
    }
};