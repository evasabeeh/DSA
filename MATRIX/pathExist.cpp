// check if path exist in graph or not, 1=src, 2=dst, 0=wall
class Solution
{
public:
    int r[4] = {0, 1, -1, 0};
    int c[4] = {1, 0, 0, -1};

    bool isSafe(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] == 0 || grid[i][j] == -1)
            return false;

        return true;
    }
    bool path(vector<vector<int>> &grid, int i, int j)
    {
        grid[i][j] = -1;

        for (int k = 0; k < 4; k++)
        {
            int x = i + r[k], y = j + c[k];

            if (isSafe(grid, x, y))
            {
                if (grid[x][y] == 2)         // destination reached
                    return true;

                if (path(grid, x, y))
                    return true;
            }
        }
        return false;
    }
    bool is_Possible(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return path(grid, i, j);
            }
        }
        return false;
    }
};