class Solution
{
public:
    int r[4] = {0, 1, 0, -1}, c[4] = {1, 0, -1, 0};
    bool checkCycle(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j, int parentI, int parentJ)
    {
        vis[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int x = r[k] + i, y = c[k] + j;

            if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() &&
                grid[i][j] == grid[x][y] && !(x == parentI && y == parentJ))
            {
                if (vis[x][y] || checkCycle(grid, vis, x, y, i, j))
                    return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && checkCycle(grid, vis, i, j, -1, -1))
                    return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/detect-cycles-in-2d-grid/