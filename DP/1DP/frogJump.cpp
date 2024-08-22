// https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost


class Solution
{
public:
    int solve(vector<int> &h, int n, vector<int> &dp, int k)
    {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (n - j >= 0)
            {
                int jump = solve(h, n - j, dp, k) + abs(h[n] - h[n - j]);
                ans = min(ans, jump);
            }
        }
        return dp[n] = ans;
    }
    int minimizeCost(vector<int> &arr, int &k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(arr, n - 1, dp, k);
    }
};