#include<bits/stdc++.h>
using namespace std;          //count number of longest increasing subsequence

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