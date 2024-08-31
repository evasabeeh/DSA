// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution
{
public:
    int mod = 1000000007;
    int solve(int k, int dice, int target, vector<vector<int>> &dp)
    {
        if (target < 0)
            return 0;

        if (target == 0 && dice == 0) // target reached and no more dices
            return dp[dice][target] = 1;

        if (target == 0 && dice != 0) // target is reached but more dices are there
            return 0;

        if (target != 0 && dice == 0)
            return 0;

        if (dp[dice][target] != -1)
            return dp[dice][target];

        long long count = 0;
        for (int i = 1; i <= k; i++)
            count += (solve(k, dice - 1, target - i, dp) % mod);

        return dp[dice][target] = count % mod;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(k, n, target, dp);
    }
};