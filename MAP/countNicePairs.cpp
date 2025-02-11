// https://leetcode.com/problems/count-nice-pairs-in-an-array/

class Solution
{
public:
    int rev(int n)
    {
        int num = 0;
        while (n)
        {
            num = num * 10 + (n % 10);
            n /= 10;
        }
        return num;
    }
    int countNicePairs(vector<int> &nums)
    {
        // nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) => nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
        map<int, int> mp;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = nums[i] - rev(nums[i]);
            if (mp.count(sum))
                count += (mp[sum] % 1000000007);
            count %= 1000000007;

            mp[sum]++;
        }

        return count;
    }
};