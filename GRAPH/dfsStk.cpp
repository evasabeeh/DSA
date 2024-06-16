#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& v, int start){
        int n=v.size();
        vector<bool> vis(n, false);
        vector<int> adj[n];
        stack<int> stk;

        for(int i=0; i<n; i++){               //create an adjacency list
            for(int j=0; j<n; j++){
                if(v[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        stk.push(start);
        while(!stk.empty()){
            int x=stk.top();
            stk.pop();
            if(!vis[x]){
                cout<<x+1<<" ";
                vis[x]=true;
            }
            for(int i: adj[x]){
                if(!vis[i])
                stk.push(i);
            }
        }
    }
};
int main(){
    vector<vector<int>> v;           //graph
    v.push_back({1, 1, 0});
    v.push_back({1, 1, 0});
    v.push_back({0, 0, 1});

    Solution obj;
    obj.dfs(v, 1);                   //start: start vertex
    return 0;
}