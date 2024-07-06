#include<bits/stdc++.h>
using namespace std;              //no. of permutations = n!
                                  //duplicates allowed
void permute(int n, int idx, vector<int> nums, vector<vector<int>> &ans){
    if(idx >= n){
        for(int i: nums)
        cout<<i;
        cout<<endl;

        ans.push_back(nums);
        return;
    }

    for(int j=idx; j<n; j++){
        swap(nums[idx], nums[j]);
        permute(n, idx+1, nums, ans);
        swap(nums[idx], nums[j]);              // backtrack so that nums become old vector only 
    }
}
int main(){
    vector<int> nums={1, 2, 3};
    vector<vector<int>> ans;
    permute(3, 0, nums, ans);
    
    return 0;
}                         