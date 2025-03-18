// https://leetcode.com/problems/longest-nice-subarray/

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int left = 0, right = 0, bitmask = 0, mx = 0;

        while (right < nums.size())
        {
            while ((bitmask & nums[right]) != 0)
                bitmask ^= nums[left++]; // then that pair is already not possible so we move forward

            bitmask |= nums[right];
            mx = max(mx, right - left + 1);

            right++;
        }

        return mx;
    }
};