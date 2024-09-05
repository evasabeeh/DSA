// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp, int swapped, int i)
    {
        if (i >= nums1.size())
            return 0;

        if (dp[i][swapped] != -1)
            return dp[i][swapped];

        int prev1 = nums1[i - 1], prev2 = nums2[i - 1]; // not making changes in original array but only variables are considered
        if (swapped)                                    // if earlier the value was swapped, then prev2 will be in nums1 and prev1 will be in nums2
            swap(prev1, prev2);

        int ans = INT_MAX;
        if (nums1[i] > prev1 && nums2[i] > prev2)
            ans = min(ans, solve(nums1, nums2, dp, 0, i + 1)); // exclude because it is already inc
        if (nums1[i] > prev2 && nums2[i] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, dp, 1, i + 1));

        return dp[i][swapped] = ans;
    }
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        return solve(nums1, nums2, dp, 0, 1);
    }
};