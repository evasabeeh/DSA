// https://leetcode.com/problems/palindrome-partitioning/submissions/1264696336/

class Solution
{
public:
    vector<vector<string>> ans;
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
    void solve(string s, vector<string> curr)
    {
        int n = s.size();

        if (n == 0)
        {
            ans.push_back(curr);
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            string temp = s.substr(0, i);
            if (ispalindrome(0, temp.size() - 1, temp))
            {
                curr.push_back(temp);
                solve(s.substr(i, n), curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> curr;
        solve(s, {});
        return ans;
    }
};