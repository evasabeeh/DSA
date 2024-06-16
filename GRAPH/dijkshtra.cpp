#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dijkshtra(vector<vector<int>>& v, int n, int start){         //find shortest path from source to all vertices
        vector<int> val(n+1, INT_MAX);
        vector<pair<int, int>> adj[n+1];
        for(auto vec: v)
        adj[vec[0]].push_back({vec[1], vec[2]});                       //because its a directed graph

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;       //minHeap where min pair.first is always at front of queue
        val[start]=0;
        q.push({0, start});

        while(!q.empty()){
            auto u=q.top();                                            //priority queue has top()
            q.pop();
            int nodeVal=u.first, node=u.second;
            for(auto neigh: adj[node]){
                int cost=nodeVal+neigh.second;
                if(cost<val[neigh.first]){
                    val[neigh.first]=cost;
                    q.push({cost, neigh.first});
                }
            }
        }
        val.erase(val.begin());
        for(int i: val){
            if(i==INT_MAX)
            return -1;                                      //means the node is left to be explored
        }
        return *max_element(val.begin(), val.end());
    }
};
int main(){
    vector<vector<int>> v;                   //weighted directed graph
    v.push_back({2, 1, 1});
    v.push_back({2, 3, 1});
    v.push_back({3, 4, 1});

    Solution obj;
    obj.dijkshtra(v, 4, 2);                   //start: start vertex
    return 0;
}


//Greedy algo: does not work for negative weights or negative cycle, for this we use Bellman-Ford algo