// if any subset exists with sum

class Solution
{
public:
    bool solve(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 1;

        if (i == arr.size() - 1)
        {
            if (sum == arr[i])
                return 1;
            else
                return 0;
        }

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool ntake = solve(i + 1, sum, arr, dp);
        bool take = 0;
        if (arr[i] <= sum)
            take = solve(i + 1, sum - arr[i], arr, dp);

        return dp[i][sum] = take || ntake;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum + 1, -1));
        return solve(0, sum, arr, dp);
    }
};