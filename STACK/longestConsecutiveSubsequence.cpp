class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());
        int mx = 0;
        for (int n : st)
        {
            if (!st.count(n - 1))
            {
                int streak = 1;

                while (st.count(n + 1))
                {
                    n++;
                    streak++;
                }
                mx = max(mx, streak);
            }
        }
        return mx;
    }
};

// http://leetcode.com/problems/longest-consecutive-sequence/