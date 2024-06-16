#include<bits/stdc++.h>                                    //sliding window
using namespace std;

void minSizeSubSum(vector<int> nums, int target){          //minimum length of subarray whose sum>=target
    int ans=INT_MAX, sum=0, i=0, j=0;

    while(i<nums.size()){
        sum+=nums[i];
        if(sum>=target){
            while(sum>=target){
                ans=min(ans, i-j+1);
                sum-=nums[j];
                j++;
            }
        }
        i++;
    }

    if(ans==INT_MAX)
    return 0;
    else
    return ans;
}

int main(){
    vector<int> vec{6, 2, -1, 9, 2, 11, -4};
    cout<<minSizeSubSum(vec, target);
    return 0;
}