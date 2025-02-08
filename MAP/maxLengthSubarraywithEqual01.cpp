class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                nums[i] = -1;
        }
        
        map<int, int> mp;
        int sum = 0, mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == 0)
                mx = i + 1;

            if (mp.find(sum) != mp.end())
            {
                int len = i - mp[sum];
                mx = max(mx, len);
            }
            else
                mp[sum] = i;
        }
        return mx;
    }
};

// https://leetcode.com/problems/contiguous-array/