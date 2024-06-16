#include<bits/stdc++.h>
using namespace std;
                                            //count all paths to destination
vector<vector<int>> vec;
void dfs(int start, vector<int> &path, vector<vector<int>>& graph, int end){
    path.push_back(start);

    if(start==end-1)
    vec.push_back(path);
    else{
        for(int i: graph[start])
        dfs(i, path, graph, end);
    }
    path.pop_back();
}
void allPathsSourceTarget(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> path;
    dfs(0, path, graph, n);
    
    for(auto v: vec){
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

        cout<<endl;
    }
}
int main(){
    vector<vector<int>> graph;
    graph.push_back({1,2});
    graph.push_back({3});
    graph.push_back({3});
    graph.push_back({});
    allPathsSourceTarget(graph);
    return 0;
}