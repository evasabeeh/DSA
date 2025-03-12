// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1

class Solution
{
public:
    vector<int> ans;
    bool ispalindrome(int m, int n, string &s)
    {
        while (m < n)
        {
            if (s[m] != s[n])
                return false;
            m++;
            n--;
        }
        return true;
    }
    int solve(string &s, int n, int i, vector<int> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;
        for (int idx = i; idx < n; idx++)
        {
            if (ispalindrome(i, idx, s))
                mini = min(mini, 1 + solve(s, n, idx + 1, dp));
        }
        return dp[i] = mini;
    }
    int palindromicPartition(string &s)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(s, n, 0, dp) - 1; // dp stores number of partitioned words so -1 for number of partitions
    }
};