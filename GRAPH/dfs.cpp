#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int j, vector<bool> &vis, vector<int> adj[]){    //recursive approach
        vis[j]=true;
        for(auto x: adj[j]){
            if(!vis[x]){
                dfs(x, vis, adj);
                cout<<x+1<<" ";
            }
        }
    }
    void traversal(vector<vector<int>>& v){
        int n=v.size();
        vector<int> adj[n];
        vector<bool> vis(n);

        for(int i=0; i<n; i++){               //create an adjacency list
            for(int j=0; j<n; j++){
                if(v[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                cout<<i+1<<" ";
                dfs(i, vis, adj);
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
    obj.traversal(v);
    return 0;
}