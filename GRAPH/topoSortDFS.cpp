#include <bits/stdc++.h>
void topoSort(vector<int> adj[], stack<int> &stk, vector<bool> &vis, int node)
{
    vis[node] = true;
    for (int j : adj[node])
    {
        if (!vis[j])
            topoSort(adj, stk, vis, j);
    }
    stk.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> adj[v];
    for (auto ee : edges)
        adj[ee[0]].push_back(ee[1]);

    vector<bool> vis(v, false);
    stack<int> stk;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            topoSort(adj, stk, vis, i);
    }
    vector<int> ans;
    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}