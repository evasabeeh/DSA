#include<bits/stdc++.h>
using namespace std;
                                           //longest subarray with max bitwise AND
int longestSubarray(vector<int>& nums) {
    int maxx=*max_element(nums.begin(), nums.end());           //maximum bitwise=largest number
    int subarray=0, ans=1;
    for(int i: nums){
        if(i==maxx)
        subarray++;
        else{
            ans=max(ans, subarray);
            subarray=0;
        }
    }
    return ans;
}

int main(){
    vector<int> vec{6, 2, 2, 2, 3, 1, 4};
    longestSubarray(vec);
    return 0;
}