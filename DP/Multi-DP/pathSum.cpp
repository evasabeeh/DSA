// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/

class Solution
{
public:
    int mod = 1000000007;
    int paths(vector<vector<int>> &grid, int i, int j, vector<vector<vector<int>>> &dp, int k, int sum)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0)
            return 0;

        sum += grid[i][j];

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            if (sum % k == 0)
                return 1;
            else
                return 0;
        }
        int rem = sum % k;
        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        int down = paths(grid, i + 1, j, dp, k, rem) % mod;
        int right = paths(grid, i, j + 1, dp, k, rem) % mod;

        return dp[i][j][rem] = (down + right) % mod;
    }
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, -1)));
        return paths(grid, 0, 0, dp, k, 0);
    }
};