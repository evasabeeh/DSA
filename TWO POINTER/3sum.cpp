// https://leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int i = 0;

        while (i < nums.size())
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum > 0)
                    k--;
                else
                    j++;
            }
            i++;
        }
        vector<vector<int>> anss(ans.begin(), ans.end());
        return anss;
    }
};