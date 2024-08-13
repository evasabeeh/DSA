
class Solution
{
public:
    // Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int nums[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                nums[i] = -1;
        }
        long long int ans = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (mp.find(sum) != mp.end())
                ans += mp[sum];

            mp[sum]++;
        }
        return ans;
    }
};