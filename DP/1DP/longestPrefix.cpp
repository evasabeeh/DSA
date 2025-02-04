// https://leetcode.com/problems/longest-happy-prefix/

class Solution
{
public:
    string longestPrefix(string s)
    {
        if (s == "")
            return s;

        int prefix = 0, suffix = 1;
        vector<int> dp(s.size(), 0);

        while (suffix < s.size())
        {
            if (s[prefix] == s[suffix])
            {
                dp[suffix] = prefix + 1;

                prefix++;
                suffix++;
            }
            else
            {
                if (prefix == 0)
                {
                    dp[suffix] = 0;
                    suffix++;
                }
                else
                    prefix = dp[prefix - 1];
            }
        }
        int len = dp.back();
        return s.substr(0, len);
    }
};