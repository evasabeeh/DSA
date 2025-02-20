// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/

class Solution
{
public:
    vector<string> ans;
    void solve(int n, string str)
    {
        if (str.size() == n)
        {
            ans.push_back(str);
            return;
        }

        str.push_back('1');
        solve(n, str);
        str.pop_back();

        if (str.empty() || str.back() != '0')
        {
            str.push_back('0');
            solve(n, str);
            str.pop_back();
        }
    }
    vector<string> validStrings(int n)
    {
        solve(n, "");
        return ans;
    }
};