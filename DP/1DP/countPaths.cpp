#include<bits/stdc++.h>
using namespace std;                //you can move forward or downward
                                    //count no. of paths to reach cell (m, n) from (1, 1)
int paths(int m, int n, vector<vector<int>>&dp) {
    if(m==1||n==1)
    return dp[m][n]=1;

    if(dp[m][n]==0)
    dp[m][n]=paths(m-1, n, dp)+paths(m, n-1, dp);

    return dp[m][n];
}
int main(){
    int m=3, n=7;
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
    paths(m, n, dp);
    cout<<dp[m][n];
}