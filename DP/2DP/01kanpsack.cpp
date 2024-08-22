#include <bits/stdc++.h>
int solve(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (weight[0] <= maxWeight)
            return value[0];
        else
            return 0;
    }
    if (dp[n][maxWeight] != -1)
        return dp[n][maxWeight];

    int inc = 0;
    if (weight[n] <= maxWeight)
    {
        inc = value[n] + solve(weight, value, n - 1, maxWeight - weight[n], dp);      // two parameters are changing
    }
    int exc = solve(weight, value, n - 1, maxWeight, dp);

    return dp[n][maxWeight] = max(inc, exc);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1));
    return solve(weight, value, n - 1, maxWeight, dp);
}

// 2D dp because 2 parameters are chaning, one is the index and the other is maxWeight

// Knapsack is sum of all weights should be less than or equal to capacity with the maximum value