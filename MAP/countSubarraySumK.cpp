class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0, i = 0, count = 0, n = nums.size();
        map<int, int> mp;
        mp[0] = 0;
        while (i < n)
        {
            sum += nums[i];

            if (sum == k)
                count++;
            if (mp.find(sum - k) != mp.end())
                count += mp[sum - k];

            mp[sum]++;

            i++;
        }
        return count;
    }
};

// count subarrays of sum K