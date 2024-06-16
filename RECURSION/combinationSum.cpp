#include<bits/stdc++.h>
using namespace std;                 //find combinations of elements in an array that sum upto the target
                                     //you can pick an element more than one time
class Solution {
public:
    vector<vector<int>> anss;
    void comb(int idx, vector<int> &candidates, int target, vector<int> &ans){
        if(idx==candidates.size()){
            if(target==0)
            anss.push_back(ans);
            return;
        }
        if(candidates[idx]<=target){
            ans.push_back(candidates[idx]);
            comb(idx, candidates, target-candidates[idx], ans);
            ans.pop_back();
        }
        comb(idx+1, candidates, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        comb(0, candidates, target, ans);
        return anss;
    }
};
int main(){
    Solution obj;
    vector<int> arr={2, 3, 1, 4};
    int target=7;
    obj.combinationSum(arr, target);
    
    for(auto v: anss){
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    }
}