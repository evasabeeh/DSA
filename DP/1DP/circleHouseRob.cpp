// https://leetcode.com/problems/house-robber-ii/

class Solution
{
public:
    int solve(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n < 0)
            return 0;

        if (n == 0)
            return nums[0];

        if (dp[n] != -1)
            return dp[n];

        int inc = solve(nums, n - 2, dp) + nums[n];
        int exc = solve(nums, n - 1, dp);

        dp[n] = max(inc, exc);

        return dp[n];
    }
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> nums2(nums.begin() + 1, nums.end());
        nums.pop_back();    // nums array is excluding first element and nums2 is excluding last element

        int n = nums.size();
        vector<int> dp1(n + 1, -1), dp2(n + 1, -1);
        return max(solve(nums, n - 1, dp1), solve(nums2, n - 1, dp2));
    }
};

// because its a circle, we can either include nums[0] or nums[n-1] so calculating for both