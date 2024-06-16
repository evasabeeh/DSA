#include<bits/stdc++.h>
using namespace std;
int maxx=-1;                                             //longest cycle in a directed graph
                                                         //DFS approach
void checkCycle(int node, vector<bool>& pathVis, vector<bool> &vis, vector<int> adj[], int dist){
    vis[node]=true;
    pathVis[node]=true;
    for(int x: adj[node]){
        if(!vis[x])
        checkCycle(x, pathVis, vis, adj, dist+1);
        else if(pathVis[x]==true)
        maxx=max(maxx, dist);
    }
    pathVis[node]=false;
}
int longestCycle(vector<int>& edges) {
    int n=edges.size();
    vector<bool> vis(n, false);
    vector<int> adj[n];
    vector<bool> pathVis(n, false);

    for(int i=0;i<n;i++){                          //reverse adj list is created. It is created for incoming edges
        if(edges[i]!=-1)                           //if no outgoing edge from node i is there, then edges[i]==-1
        adj[edges[i]].push_back(i);
    }

    for(int i=0;i<n;i++){
        if(!vis[i])
        checkCycle(i, pathVis, vis, adj, 1);
    }
    return maxx;
}

int main(){
    vector<int> edges={3, 3, 4, 2, 3};                //node i is directed to edges[i]

    cout<<longestCycle(edges);

    return 0;
}