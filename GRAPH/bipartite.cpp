#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int col, vector<int>&colour, vector<int>adj[], int src){
        colour[src]=col;
        for(auto x: adj[src]){
            if(colour[x]==col)                        //if adj node is already coloured
            return false;
            if(colour[x]==-1){
                if(!dfs(!col, colour, adj, x))        //adj node with opposite colour
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph, int n) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++)
            adj[i].push_back(graph[i][j]);
        }

        vector<int> colour(n, -1);
        for(int i=0;i<n;i++){                     //connected components
            if(colour[i]==-1){
                if(!dfs(1, colour, adj, i))
                return false;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<int>> graph;                   //undirected graph
    graph.push_back({1, 2, 3});
    graph.push_back({0, 2});
    graph.push_back({0, 1, 3});
    graph.push_back({0, 2});

    Solution obj;
    cout<<obj.isBipartite(graph, 4);
    return 0;
}