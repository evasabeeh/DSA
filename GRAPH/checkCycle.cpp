#include<bits/stdc++.h>
using namespace std;
//check for a back edge present in the graph. A back edge is an edge that is indirectly joining a node to itself or one of its ancestors(self-loop).

bool checkCycle(int node, int parent, vector<bool> &vis, vector<int> adj[]){
    vis[node]=true;
    for(auto x: adj[node]){
        if(!vis[x]){
            if(checkCycle(x, node, vis, adj))
            return true;
        }
        else if(x!=parent)
        return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V+1, false);

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(checkCycle(i, -1, vis, adj))
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> adj[8];
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[4].push_back(3);
    adj[3].push_back(4);

    adj[2].push_back(3);
    adj[3].push_back(2);                  

   /*
   for(int i=0;i<n;i++)                   for directed graph, incoming edges are considered for list
    adj[v].push_back(u);
   */

    cout<<isCycle(5, adj);

    return 0;
}

/*
bool checkCycle(int node, vector<bool>& pathVis, vector<bool> &vis, vector<int> courses[]){
    vis[node]=true;
    pathVis[node]=true;
    for(auto x: courses[node]){
        if(!vis[x]){
            if(checkCycle(x, pathVis, vis, courses))
            return true;
        }
        else if(pathVis[x])
        return true;
    }
    pathVis[node]=false;
    return false;
}
*/