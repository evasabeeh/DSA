
class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                // just larger value index in ans, that will be replaced by this lower val
                int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[idx] = a[i];
            }
        }
        return ans.size();
    }
};
