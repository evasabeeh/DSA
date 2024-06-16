#include<bits/stdc++.h>
using namespace std;                              //create pascal's triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        numRows--;
        if(numRows==0)
        return ans;

        for(int k=1;k<=numRows;k++){
            vector<int> v;
            v.push_back(1);

            for(int i=1; i<k; i++)
            v.push_back(ans[k-1][i]+ans[k-1][i-1]);
            
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> ans=obj.generate(6);
    for(auto v: ans){
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<endl;
    }
}