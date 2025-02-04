// https://leetcode.com/problems/word-break/description/

class Solution
{
public:
    bool solve(int i, string &s, set<string> &st, vector<int> &dp)
    {
        if (i >= s.size())
            return true;

        if (dp[i] != -1)
            return dp[i];

        bool ans = 0;
        string str = "";
        for (int j = i; j < s.size(); j++)
        {
            str.push_back(s[j]);

            if (st.count(str))
                ans = ans || solve(j + 1, s, st, dp);
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, st, dp);
    }
};