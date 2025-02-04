class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int pivot = -1;                         // the first rotated element
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                pivot = i;
                break;
            }
        }
        if (pivot == -1)                        // no pivot means no rotation needed 
            return true;

        int first = nums[0];                    // because on rotation last element will go ahead then again urr last will go ahead and so on
        for (int i = nums.size() - 1; i >= pivot; i--)
        {
            if (nums[i] > first)
                return false;
            first = nums[i];
        }
        return true;
    }
};

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/