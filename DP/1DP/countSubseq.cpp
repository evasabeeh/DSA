// it will count all subsequences including duplicates
class Solution
{
public:
    int mod = 1000000007;

    int solve(string s, int i, vector<int> &dp)
    {
        if (i >= s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int count = 0;
        count += (solve(s, i + 1, dp) % mod);
        count += ((1 + (solve(s, i + 1, dp) % mod)) % mod);

        return dp[i] = count;
    }
    int distinctSubseqII(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return solve(s, 0, dp);
    }
};