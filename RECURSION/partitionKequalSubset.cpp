// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
// TLE -> bit masking is used

class Solution
{
public:
    bool solve(vector<int> &nums, int i, int curr, int sum, vector<bool> &vis, int k)
    {
        if (k == 1) // because we are traversing from larger num to small num, if k-1 subsets are formed, last subset is also valid
            return true;

        if (curr > sum)
            return false;

        if (curr == sum) // subset sum reached, one partition made => k-1
            return solve(nums, 0, 0, sum, vis, k - 1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (!vis[i] && nums[i] <= sum)
            {
                vis[i] = true;
                if (solve(nums, i + 1, curr + nums[i], sum, vis, k))
                    return true;
                vis[i] = false; // backtrack
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0)
            return false;

        sum /= k;
        sort(nums.rbegin(), nums.rend());          // so that first larger num is used
        vector<bool> vis(nums.size(), false);
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));

        return solve(nums, 0, 0, sum, vis, k);
    }
};