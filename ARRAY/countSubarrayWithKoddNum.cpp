class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0) // replace even with 0 and odd with 1
                nums[i] = 0;
            else
                nums[i] = 1;
        }
        int left = 0, right = 0, ans = 0, sum = 0;
        while (right < nums.size())
        {
            sum += nums[right];

            while (sum > k)
            {
                sum -= nums[left];
                left++;
            }
            if (sum == k)
            {
                ans++;
                int i = left;
                while (i < right && nums[i] == 0)
                {
                    ans++;
                    i++;
                }
            }
            right++;
        }
        return ans;
    }
};

// https://leetcode.com/problems/count-number-of-nice-subarrays/