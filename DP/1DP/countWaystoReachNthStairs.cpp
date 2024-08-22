#include <bits/stdc++.h>
int countDistinctWays(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;         // order does matter
       // dp[i] = ( 1+ min (dp[i - 1] + dp[i - 2])) % 1000000007;              order does not matter

    return dp[n];
}

// climb either 1 or 2 stairs at a time
// from 0th to nth stair

/*
int solve(int n){
}
*/