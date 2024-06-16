#include<bits/stdc++.h>
using namespace std;
                                               //Kahn's BFS algorithm
class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>> graph, int n){ 
        vector<int> adj[n];
        vector<int> inDegree(n, 0);
        vector<int> path;
        for(auto v: graph){
            adj[v[0]].push_back(v[1]);           
            inDegree[v[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            path.push_back(x);

            for(auto v: adj[x]){
                if(--inDegree[v]==0)
                q.push(v);
            }
        }
        if(path.size()==n)                      //there is no cycle
        return path;

        return {};
    }
};
int main(){
    vector<vector<int>> graph;                   //directed graph
    graph.push_back({5, 2});
    graph.push_back({5, 0});
    graph.push_back({4, 0});
    graph.push_back({4, 1});
    graph.push_back({2, 3});
    graph.push_back({3, 1});

    Solution obj;
    vector<int> sorted=obj.topologicalSort(graph, 6);
    for(int i: sorted)
    cout<<i<<" ";
    return 0;
}