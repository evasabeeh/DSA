#include<bits/stdc++.h>
using namespace std;
int minn=INT_MAX;                                        //shortest cycle in an undirected graph
                                                         //BFS approach, DFS will give TLE
void checkCycle(int i, vector<int> adj[], int n){
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(i);
    dist[i]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto y: adj[x]){
            if(dist[y]==INT_MAX){
                q.push(y);
                dist[y]=dist[x]+1;
                parent[y]=x;
            }
            else if(parent[y]!=x&&parent[x]!=y)
            minn=min(minn, dist[x]+dist[y]+1);
        }
    }
}
int isCycle(int n, vector<int>&adj[]) {
    vector<int> adj[n];

    for(int i=0;i<n;i++)
    checkCycle(i, adj, n);
    
    if(minn==INT_MAX)
    return -1;

    return minn;
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

    cout<<isCycle(5, adj);

    return 0;
}