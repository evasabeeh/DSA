// https://leetcode.com/problems/pizza-with-3n-slices/description/

class Solution
{
public:
    int solve(vector<int> &nums, int i, int n, int maxi, vector<vector<int>> &dp)
    {
        if (i > n || maxi == 0)
            return 0;

        if (dp[i][maxi] != -1)
            return dp[i][maxi];

        int inc = solve(nums, i + 2, n, maxi - 1, dp) + nums[i];
        int exc = solve(nums, i + 1, n, maxi, dp);

        return dp[i][maxi] = max(inc, exc);
    }
    int maxSizeSlices(vector<int> &slices)
    { // because there are 3*n = k slices, every one will get n = k/3 slices, so you need to eat k/3 slices

        int k = slices.size();
        vector<vector<int>> dp1(k + 1, vector<int>(k + 1, -1));
        vector<vector<int>> dp2(k + 1, vector<int>(k + 1, -1));

        return max(solve(slices, 0, k - 2, k / 3, dp1), solve(slices, 1, k - 1, k / 3, dp2));
    }
};