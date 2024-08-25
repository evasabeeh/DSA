// https://leetcode.com/problems/minimum-cost-for-tickets/description/

class Solution
{
public:
    int solve(int i, vector<int> &days, vector<int> &cost, vector<int> &dp)
    {
        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int opt1 = cost[0] + solve(i + 1, days, cost, dp); // for day-1 pass

        int idx = i;
        for (; idx < days.size() && days[idx] < days[i] + 7; idx++);
        int opt2 = cost[1] + solve(idx, days, cost, dp); // for days 7 pass

        for (; idx < days.size() && days[idx] < days[i] + 30; idx++);
        int opt3 = cost[2] + solve(idx, days, cost, dp); // for days 30 pass

        dp[i] = min({opt1, opt2, opt3});                     // min cost

        return dp[i];
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size() + 1, -1);
        return solve(0, days, costs, dp);
    }
};