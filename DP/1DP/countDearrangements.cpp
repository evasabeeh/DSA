#include <bits/stdc++.h>
#define MOD 1000000007                       // count permutations such that no element is on its original position
long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (((n - 1) % MOD) * ((solve(n - 1, dp) % MOD) + (solve(n - 2, dp) % MOD))) % MOD;         // (n-1) boxes are left to be filled * f(n-1) numbers are there to be filled * f(n-2) when two numbers are swapped hence placed

    return dp[n];
}
long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, -1);
    return solve(n, dp);
}

// https://www.naukri.com/code360/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM