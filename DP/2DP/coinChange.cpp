// https://leetcode.com/problems/coin-change-ii/

class Solution
{
public:
    int solve(vector<int> &num, int target, int i, vector<vector<int>> &dp)
    {
        if (i >= num.size())
            return 0;

        if (target < 0)
            return 0;

        if (target == 0)
            return 1;

        if (dp[i][target] != -1)
            return dp[i][target];

        int inc = solve(num, target - num[i], i, dp); // coins can be repeated
        int exc = solve(num, target, i + 1, dp);

        return dp[i][target] = inc + exc; // total ways
    }
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(coins, amount, 0, dp);
    }
};