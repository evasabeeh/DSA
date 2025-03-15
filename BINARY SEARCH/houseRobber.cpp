class Solution
{
public:
    bool canRob(vector<int> &nums, int mid, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                if (--k == 0) // at least k houses are robbed, return true
                    return true;

                i++; // so that adjacent houses are only robbed
            }
        }
        return false;
    }
    int minCapability(vector<int> &nums, int k)
    {
        // left and right is denoting capability
        int left = 1, right = *max_element(nums.begin(), nums.end()), ans = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (canRob(nums, mid, k))
            { // if it has capability as mid, then he can rob only nums[i] <= mid
                ans = min(ans, mid);
                right = mid - 1; // because we need to find min of all capabilities we are moving to left
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};

// https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15