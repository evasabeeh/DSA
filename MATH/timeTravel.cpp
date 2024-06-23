#include<bits/stdc++.h>
using namespace std;
void timeTravel(vector<int>adj[], vector<int> tim, int cities){
    
}
int main(){
    int cities, records;  cin>>cities>>records;
    vector<vector<vector<int>>> edges;
    for(int i=0;i<records;i++){
        int roads;  cin>>roads;
        vector<vector<int>> vec;
        while(roads--){
            int u, v;  cin>>u>>v;
            vec.push_back({u, v});
        }
        edges.push_back(vec);
    }
    int moments;  cin>>moments;
    vector<int> tim;
    for(int i=0;i<moments;i++){
        int t;  cin>>t;
        tim.push_back(t);
    }
    //create an adjacency List
    vector<int> adj[cities];
    for(auto vec: edges){
        for(int i=0;i<vec.size();i++){
            adj[vec[i][0]].push_back(vec[i][1]);
            adj[vec[i][1]].push_back(vec[i][0]);
        }
    }
    timeTravel(adj, tim, cities);
    return 0;
}