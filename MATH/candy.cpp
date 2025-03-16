// https://leetcode.com/problems/candy/submissions/1051095644/

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candy(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
                candy[i] = candy[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i] && candy[i] <= candy[i + 1])
                candy[i] = candy[i + 1] + 1;
        }
        int ans = accumulate(candy.begin(), candy.end(), 0);
        return ans;
    }
};