#include<bits/stdc++.h>
using namespace std;          
                               //if there exists subset that sum upto target
bool subsequence(int idx, vector<int> nums, int target, vector<vector<int>>&dp){
    if(idx<0 || target<0)
    return false;

    if(target==0)
    return true;

    if(dp[idx][target]!=-1)
    return dp[idx][target];

    bool include=subsequence(idx-1, nums, target-nums[idx], dp);
    bool exclude=subsequence(idx-1, nums, target, dp);

    return dp[idx][target]=include||exclude;
}
int main(){
    vector<int> nums={1, 5, 11, 5};
    int target=6;
    vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
    cout<<subsequence(3, nums, target, dp);
    
    return 0;
}                       

//subsequences are contiguous or non-contiguous part of a sequence but in same order

/*  Recursive approach
bool subsequence(int idx, vector<int> nums, int target){
    if(idx>=nums.size())
    return false;
    if(target<0)
    return false;
    if(target==0)
    return true;

    int include=subsequence(idx+1, nums, target-nums[idx]);
    int exclude=subsequence(idx+1, nums, target);

    return include|exclude;
}
*/