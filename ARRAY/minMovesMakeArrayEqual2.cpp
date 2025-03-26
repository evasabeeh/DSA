class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2], count = 0;
        if (nums.size() % 2 != 1)
            median = (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
        int counter = 0;
        for (int i : nums)
            counter += abs(i - median);

        return counter;
    }
};

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/