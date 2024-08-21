// https://www.naukri.com/code360/problems/minimum-elements_3843091?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h>
int solve(vector<int> &nums, int x, vector<int> &dp)
{
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solve(nums, x - nums[i], dp);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    dp[x] = mini;
    return mini;
}
int minimumElements(vector<int> &nums, int x)
{
    vector<int> dp(x + 1, -1);
    int ans = solve(nums, x, dp);
    if (ans == INT_MAX)
        return -1;

    return ans;
}

/*

Recursion


int solve(vector<int> &nums, int x){
    if(x==0)
    return 0;

    if(x<0)
    return INT_MAX;

    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        int ans=solve(nums, x-nums[i]);
        if(ans!=INT_MAX)
        mini=min(mini, 1+ans);
    }
    return mini;
}
int minimumElements(vector<int> &nums, int x)
{
    int ans=solve(nums, x);
    if(ans==INT_MAX)
    return -1;

    return ans;
}
*/