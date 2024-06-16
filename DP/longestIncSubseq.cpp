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