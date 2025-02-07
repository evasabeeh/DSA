class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long count = 0, zero = 0;
        int right = 0, n = nums.size();
        while (right < n)
        {
            if (nums[right++] == 0)
            {
                zero++;
                count += zero;    // or do once, count += ((zero * (zero+1))/2)
            }
            else
                zero = 0;
        }

        return count;
    }
};

// https://leetcode.com/problems/number-of-zero-filled-subarrays/