class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = t.size() - 1; j >= 0; j--)
            {
                int inc = 0, exc = 0;
                if (s[i] == t[j])
                    inc = 1 + dp[i + 1][j + 1];
                exc = max(dp[i + 1][j], dp[i][j + 1]);

                dp[i][j] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
};