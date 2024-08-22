// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// House Robber

#include <bits/stdc++.h>
int solve(vector<int> &nums, int n, vector<int> &dp)           // we are traversing back to front in array
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int inc = solve(nums, n - 2, dp) + nums[n];
    int exc = solve(nums, n - 1, dp);

    dp[n] = max(inc, exc);

    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(nums, n - 1, dp);
}

/*
#include <bits/stdc++.h>
int solve(vector<int> &nums, int n){
    if(n<0)
    return 0;

    if(n==0)
    return nums[0];

    int inc=solve(nums, n-2)+nums[n];     // if element is included
    int exc=solve(nums, n-1);

    return max(inc, exc);
}
int maximumNonAdjacentSum(vector<int> &nums){
    return solve(nums, nums.size()-1);
}
*/