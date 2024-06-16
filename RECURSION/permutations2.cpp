#include<bits/stdc++.h>
using namespace std;              //no. of permutations = n!
                                  //unique permutations
set<vector<int>> s;
void temp(vector<int>& nums, int start, int end){
    if(start==end){
        s.insert(nums);
    }
    for(int i=start;i<=end;i++){
        swap(nums[start], nums[i]);
        temp(nums, start+1, end);
        swap(nums[start], nums[i]); //backtracking
    }
}
void permute(vector<int>& nums) {
    temp(nums, 0, nums.size()-1);
    for(auto i=s.begin(); i!=s.end();i++){
        vector<int> v=*i;
        for(int j=0;j<v.size();j++){
            cout<<v[j];
        }
        cout<<endl;
    }
}
int main(){
    vector<int> vec={2, 1, 1};
    permute(vec);
    return 0;
}                         