// https://leetcode.com/problems/cherry-pickup/

class Solution
{
public:
    int dp[52][52][52][52]; // [0][1] - path 1; [2][3] - path 2
    int solve(vector<vector<int>> &grid, int i, int j, int x, int y, int n)
    {
        if (i >= n || j >= n || i < 0 || j < 0 || x >= n || y >= n || x < 0 || y < 0 || grid[i][j] == -1 || grid[x][y] == -1) // invalid
            return INT_MIN;

        if ((i == n - 1 && j == n - 1) || (x == n - 1 && y == n - 1)) // reached destination
            return grid[n - 1][n - 1];

        if (dp[i][j][x][y] != -1)
            return dp[i][j][x][y];

        int cherries = 0;
        if (i == x && j == y) // collected only once
            cherries += grid[i][j];
        else
            cherries += (grid[i][j] + grid[x][y]);

        int DD = solve(grid, i + 1, j, x + 1, y, n); // when both the paths coming from down-down
        int DR = solve(grid, i + 1, j, x, y + 1, n); // when paths are coming from down and right
        int RD = solve(grid, i, j + 1, x + 1, y, n);
        int RR = solve(grid, i, j + 1, x, y + 1, n);

        return dp[i][j][x][y] = cherries + max({DD, DR, RD, RR});
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        int ans = solve(grid, 0, 0, 0, 0, grid.size()); // because we need to come first from top to down then again from bottom to up, so we can traverse at once only by taking two different paths

        if (ans >= 0)
            return ans;

        return 0;
    }
};

