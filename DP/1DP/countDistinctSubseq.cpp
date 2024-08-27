// count distinct subsequences

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
        vector<bool> vis(26, false);
        for (int j = i; j < s.size(); j++)
        {
            if (vis[s[j] - 'a'])
                continue;

            vis[s[j] - 'a'] = true;

            count = (count + 1 + solve(s, j + 1, dp)) % mod; // include unique char in subsequence for particular moment
        }
        return dp[i] = count;
    }
    int distinctSubseqII(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return solve(s, 0, dp) % mod;
    }
};

/*
class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> dp(s.size() + 1, 0);
        int mod = 1000000007;

        for(int i = s.size() - 1; i >= 0; i--){
            vector<bool> vis(26, false);
            int count = 0;
            for(int j = i; j < s.size(); j++){
                if(vis[s[j] - 'a'] == false){
                    vis[s[j] - 'a'] = true;
                    count = (count + 1 + dp[j + 1]) % mod;
                }
            }
            dp[i] = count;
        }

        return dp[0] % mod;
    }
};
*/