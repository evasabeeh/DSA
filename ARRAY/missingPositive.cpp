class Solution
{
public: // cyclic sort
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1; // if all are correct then last number is returned
    }
};

// first place all the elements in the range [1, n] at their correct positions,ie, x-1th index
// then check which index+1 is not matching with number and that will be our missing +ve