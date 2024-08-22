#include<bits/stdc++.h>
using namespace std;
int findCatalan(int n){
    int dp[n+1];
    dp[0]=1, dp[1]=1;
    for(int i=2;i<=n;i++){
        int ans=0;
        for(int j=0;j<i;j++){
            ans+=((dp[j]*dp[i-j-1])%1000000007);
        }
        dp[i]=ans;
    }
    return dp[n];
}
int main(){
    int ans=findCatalan(5);
    cout<<ans;
}

//Count the number of expressions containing n pairs of parentheses
//Count the number of possible Binary Search Trees with n keys