class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minima = prices[0], ans = 0;
        for (int i : prices)
        {
            int profit = i - minima;     // if sold on current day
            ans = max(ans, profit);      // max profit till now
            minima = min(minima, i);     // minima till now
        }
        return ans;
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1458408041/