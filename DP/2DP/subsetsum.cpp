// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


class Solution
{
public:
    bool solve(vector<int> &arr, int target, vector<vector<int>> &dp, int i)
    {
        if (target == 0)
            return 1;

        if (i >= arr.size())
            return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool inc = 0;
        if (arr[i] <= target)
            inc = solve(arr, target - arr[i], dp, i + 1);

        bool exc = solve(arr, target, dp, i + 1);

        return dp[i][target] = inc || exc;
    }
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(arr, target, dp, 0);
    }
};