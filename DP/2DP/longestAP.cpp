// https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;

        unordered_map<int, int> dp[n + 1];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int d = nums[i] - nums[j];
                int count = 1;
                if (dp[j].count(d)) // number of elements with same difference
                    count = dp[j][d];

                dp[i][d] = count + 1; // i is included so count + 1
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};

// dp[i][d] stores the length of longest AP till i index with difference d
// at particular index, we can have multiple differences

/*          TLE
class Solution
{
public:
    int solve(vector<int> &nums, int i, int d, unordered_map<int, int> dp[])
    { // check for same diff elements in backward array
        if (i < 0)
            return 0;

        if (dp[i].count(d))
            return dp[i][d];

        int ans = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] - nums[j] == d)
                ans = max(ans, 1 + solve(nums, j, d, dp));
        }
        return dp[i][d] = ans;
    }
    int longestArithSeqLength(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        unordered_map<int, int> dp[nums.size() + 1];
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                ans = max(ans, solve(nums, i, nums[j] - nums[i], dp));
        }
        ans += 2; // 2 is added because nums[i] and nums[j] both are added to the AP
        return ans;
    }
};
*/

// dp[i][d] stores the length of longest AP till i index with difference d
// at particular index, we can have multiple differences