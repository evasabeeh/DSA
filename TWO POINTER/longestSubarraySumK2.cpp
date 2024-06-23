#include<bits/stdc++.h>
using namespace std;
                                           //longest subarray with sum K
                                           //for positives and 0's
int longestSubarraySumK(vector<int> &arr, int k){
	int maxx=0, sum=arr[0];
    int i=0, j=0;
    int n=arr.size();
    while(j<n){
        while(sum>k&&i<=j){
            sum-=arr[i];
            i++;
        }
        if(sum==k)
        maxx=max(maxx, j-i+1);
        j++;
        if(j<n)
        sum+=arr[j];
    }
    return maxx;
}

int main(){
    vector<int> vec{5, 1, 2, 3, 1, 1, 0, 0, 4, 1, 1, 1, 1, 1};
    cout<<longestSubarraySumK(vec, 9);
    return 0;
}