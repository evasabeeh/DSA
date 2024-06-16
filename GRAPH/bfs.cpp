#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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
                vis[i]=true;                           //start from a vertex
                queue<int> q;
                q.push(i);

                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    cout<<x+1<<" ";

                    for(int i: adj[x]){
                        if(!vis[i]){
                            vis[i]=true;
                            q.push(i);
                        }
                    }
                }
            }
        }
    }
};
int main(){
    vector<vector<int>> v;
    v.push_back({1, 1, 0, 1});
    v.push_back({1, 1, 0, 1});
    v.push_back({0, 0, 1, 1});
    v.push_back({0, 0, 0, 1});

    Solution obj;
    obj.traversal(v);
    return 0;
}