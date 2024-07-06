#include<bits/stdc++.h>
using namespace std;                    // 2^n subsets including empty

void solve(vector<char> &set, vector<vector<char>> &ans, vector<char> temp, int idx){
    if(idx >= set.size()){
        for(char i: temp)
        cout<<i<<" ";
        cout << endl;

        ans.push_back(temp);
        return;
    }

    // exclude
    solve(set, ans, temp, idx + 1);

    //include
    temp.push_back(set[idx]);
    solve(set, ans, temp, idx + 1);
}
int main(){
    vector<char> set={'A', 'B', 'C', 'D'};
    vector<char> temp;
    vector<vector<char>> ans;

    solve(set, ans, temp, 0);
    
    return 0;
}                                     //O(2^n)