// https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1//{ Driver Code Starts
// Initial Template for C++

class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, solve(n - (i * i), dp) + 1);
        }
        dp[n] = ans;
        return dp[n];
    }
    int MinSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};