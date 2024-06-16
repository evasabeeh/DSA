#include<bits/stdc++.h>
using namespace std;           //print largest subset having nums[i]%nums[j]==0
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        int maxx=1, lastIdx=0;
        vector<int> dp(n, 1), hash(n);   //hash to store indices

        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxx){
                maxx=dp[i];
                lastIdx=i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx=hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> arr={1, 8, 4, 9, 240};
    vector<int> ans=obj.largestDivisibleSubset(arr);
    
    for(int i: ans)
    cout<<i<<" ";
}