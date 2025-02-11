// https://leetcode.com/problems/count-number-of-bad-pairs/description/?envType=daily-question&envId=2025-02-09

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        long long count = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {                           // count good pairs
            int diff = nums[i] - i; // j - i = nums[j] - nums[i] => i - nums[i] = nums[j] - j
            if (mp.find(diff) != mp.end())
                count += mp[diff];

            mp[diff]++; // so that if first time sum if found, it is not counted in good pairs
        }
        long long ans = (static_cast<long long>(n) * (n - 1) / 2) - count; // badPairs = totalPairs - goodPairs;
        return ans;
    }
};