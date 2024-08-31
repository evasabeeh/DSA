// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution
{
public:
    bool solve(vector<int> &nums, int i, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;

        if (i >= nums.size())
            return false;

        if (target < 0)
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        int inc = solve(nums, i + 1, target - nums[i], dp);
        int exc = solve(nums, i + 1, target, dp);

        return dp[i][target] = inc || exc;
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 == 1)
            return false;

        sum /= 2;
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        return solve(nums, 0, sum, dp);
    }
};