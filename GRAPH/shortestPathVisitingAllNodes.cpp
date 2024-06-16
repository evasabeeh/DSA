#include<bits/stdc++.h>
using namespace std;
                           //shortest path length from any node visiting all nodes, nodes can be revisited
class Solution{
public:
    int shortestPath(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int, pair<int, int>>> q;                 // {node, {dist, mask}}    //mask to keep check for visited nodes(set bit = visited)
        set<pair<int, int>> visited;                        // store visited paths {node, mask}
        for(int i=0;i<n;i++){
            int mask=1<<i;
            q.push({i, {0, mask}});
            visited.insert({i, mask});
        }
        while(!q.empty()){
            int node=q.front().first, dist=q.front().second.first, mask=q.front().second.second;
            q.pop();
            for(int adj: graph[node]){
                int newMask=(mask|(1<<adj));                // 01000|(01000<<3)=01010
                if(newMask==((1<<n)-1))                     // mask==(1<<n)-1       means all nodes visited  
                return ++dist;
                else if(visited.count({adj, newMask}))
                continue;
                else{
                    q.push({adj, {dist+1, newMask}});
                    visited.insert({adj, newMask});
                }
            }
        }
        return 0;
    }
};
int main(){
    vector<vector<int>> v;
    v.push_back({1, 2, 3});
    v.push_back({0});
    v.push_back({0});
    v.push_back({0});

    Solution obj;
    int len=obj.shortestPath(v); 
    cout<<len;
    return 0;
}
