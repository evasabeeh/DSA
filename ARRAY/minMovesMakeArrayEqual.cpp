/ https : // leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/submissions/1586529905/?envType=daily-question&envId=2025-03-26

          class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> arr;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        { // middle element that can be reached
            for (int j : grid[i])
                arr.push_back(j);
        }
        sort(arr.begin(), arr.end());
        int median = arr[(m * n) / 2], count = 0;
        for (int i : arr)
        { // check all the elements if on adding it or on subtracting it becomes median
            int steps = abs(i - median);
            if (steps % x != 0)
                return -1;

            count += steps / x;
        }
        return count;
    }
};