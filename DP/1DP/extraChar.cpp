// leetcode.com/problems/extra-characters-in-a-string/submissions/1399300190/?envType=daily-question&envId=2024-09-23

class Solution
{
public:
    int solve(int i, string s, set<string> &st, vector<int> &dp)
    {
        if (i >= s.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        string str = "";
        int ans = s.size();
        for (int j = i; j < s.size(); j++)
        {
            str.push_back(s[j]);

            int extra = 0;
            if (!st.count(str)) // if not in dictionary
                extra = str.size() + solve(j + 1, s, st, dp);
            else // find next substring
                extra = solve(j + 1, s, st, dp);

            ans = min(ans, extra);
        }
        return dp[i] = ans;
    }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        set<string> st(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, st, dp);
    }
};