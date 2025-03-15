https : // leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13

        class Solution
{
public: // Range Update
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int counter = 0, sum = 0;             // count the queries applied and decrement
        vector<int> diff(nums.size() + 1, 0); // prefix sums
        for (int i = 0; i < nums.size(); i++)
        {
            while (sum + diff[i] < nums[i])
            { // means need more decrement
                counter++;
                if (counter > queries.size())
                    return -1;

                int l = queries[counter - 1][0], r = queries[counter - 1][1], v = queries[counter - 1][2];
                if (r >= i)
                { // if query range affects the current index
                    diff[max(l, i)] += v;
                    diff[r + 1] -= v;
                }
            }
            sum += diff[i];
        }
        return counter;
    }
};