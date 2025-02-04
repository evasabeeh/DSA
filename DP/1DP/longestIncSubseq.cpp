#include<bits/stdc++.h>
using namespace std;          //Length of longest increasing subsequence

int lis(vector<int>arr){
    int maxx=1, n=arr.size();
    vector<int> dp(n, 1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
            dp[i]=max(dp[i], dp[j]+1);
        }
        maxx=max(maxx, dp[i]);
   }
    return maxx;
}
int main(){
    vector<int> arr={10,9,2,5,3,7,101,18};
    cout<<lis(arr);
}

/*
class Solution {
public:
    int solve(vector<int> &nums, int curr_idx, int prev_element){      // idx of curr element is taken while prev element is taken
        if(curr_idx >= nums.size())
        return 0;

        int inc = 0;
        if(prev_element < nums[curr_idx])
        inc = 1 + solve(nums, curr_idx + 1, nums[curr_idx]);         // if curr element is inc then made it prev
        int exc = solve(nums, curr_idx + 1, prev_element);           // if not taken

        return max(inc, exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, INT_MIN);
    }
};
*/