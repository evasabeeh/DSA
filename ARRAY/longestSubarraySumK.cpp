#include<bits/stdc++.h>
using namespace std;
                                           //longest subarray with sum K
                                           //for 0's, negatives and positives
int longestSubarraySumK(vector<int> &arr, int k){
	int maxx=0, sum=0;
    unordered_map<int, int> mp;

    for(int i=0;i<arr.size();i++){
        sum+=arr[i];

        if(sum==k)
        maxx=i+1;
        
        int rem=sum-k;
        if(mp.find(rem)!=mp.end()){
            int len=i-mp[rem];
            maxx=max(maxx, len);
        }
        if(mp.find(sum)==mp.end())
        mp[sum]=i;
    }
    return maxx;
}

int main(){
    vector<int> vec{5, 1, 2, 3, 1, 1, 0, 0, 4, 1, 1, 1, 1, 1};
    cout<<longestSubarraySumK(vec, 5);
    return 0;
}