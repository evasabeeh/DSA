#include<bits/stdc++.h>
using namespace std;          //count number of longest increasing subsequence
int memo(int curr, vector<int> &nums, int prev){
    if(curr == nums.size())
    return 0;

    // include
    int inc=0;
    if(prev == -1 || nums[curr]>nums[prev])
    inc = 1 + memo(curr+1, nums, curr);

    int exc = memo(curr + 1, nums, prev);

    return max(inc, exc);              // dp[curr][prev+1]  => so that invalid index is not given when prev == -1
}
int lis(vector<int>nums){
    int maxx=0, n=nums.size();
    vector<int> dp(n, 1), count(n, 1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(dp[i]==dp[j]+1)
                count[i]+=count[j];
                
                else if(dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
            }
        }
        maxx=max(maxx, dp[i]);
    }
    int counter=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxx)
        counter+=count[i];
    }
    return counter;
}
int main(){
    vector<int> arr={10,9,2,5,3,7,101,18};
    cout<<lis(arr);
}

/*
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    int maxx=0;
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int take=0, notTake=0;
            if(prev==-1 || arr[curr]>arr[prev])
            take=1+dp[curr+1][curr+1];
            else
            notTake=dp[curr+1][prev+1];

            dp[curr][prev+1]=max(take, notTake);
        }
    }
    return dp[0][0];
}
*/