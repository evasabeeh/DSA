// https://leetcode.com/problems/distinct-subsequences/

class Solution
{
public:
    int solve(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        if (j >= t.size())       // whole target is formed => reached the end of target string
            return 1;

        if (i >= s.size())      // target string not formed
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int count = 0;
        count += solve(s, t, i + 1, j, dp);        // count distinct subsequence

        if (s[i] == t[j])
            count += solve(s, t, i + 1, j + 1, dp);

        return dp[i][j] = count;
    }
    int numDistinct(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(s, t, 0, 0, dp);
    }
};