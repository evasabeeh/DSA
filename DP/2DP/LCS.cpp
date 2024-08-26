// Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution
{
public:
    int solve(string text1, string text2, int i1, int i2, vector<vector<int>> &dp)      // Memoization
    {
        if (i1 >= text1.size() || i2 >= text2.size())
            return 0;

        if (dp[i1][i2] != -1)
            return dp[i1][i2];

        int inc = 0, exc = 0;
        if (text1[i1] == text2[i2])
            inc = 1 + solve(text1, text2, i1 + 1, i2 + 1, dp);
        else
            exc = max(solve(text1, text2, i1 + 1, i2, dp), solve(text1, text2, i1, i2 + 1, dp)); // any common subsequence

        return dp[i1][i2] = max(inc, exc);
    }
    int solve2(string text1, string text2, int i1, int i2)         // Tabulation
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int> (text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; i--)
        {
            for (int j = text2.size() - 1; j >= 0; j--)
            {
                int inc = 0, exc = 0;
                if (text1[i] == text2[j])
                    inc = 1 + dp[i + 1][j + 1];
                exc = max(dp[i + 1][j], dp[i][j + 1]);

                dp[i][j] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};