class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int a = nums[0], b = INT_MAX;
        for (int i : nums)
        {
            if (i <= a)
                a = i;
            else if (i <= b)
                b = i;
            else
                return true;
        }
        return false;
    }
};


// https://leetcode.com/problems/increasing-triplet-subsequence/