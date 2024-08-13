// https://www.naukri.com/code360/problems/prim-s-mst_1095633

#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> key(n + 1, INT_MAX);      // edge weight
    vector<int> mst(n + 1, false);        // nodes included in MST
    vector<int> parent(n + 1, -1);

    key[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++)
        { // find min node
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        mst[u] = true; // mark min node

        for (auto itr : adj[u])
        { // find adjacent nodes
            int v = itr.first, w = itr.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;

    for (int i = 2; i <= n; i++)
        ans.push_back({{parent[i], i}, key[i]});

    int total = 0;
    for (int i = 0; i < V; i++)
    {
        if (key[i] != INT_MAX)
            total += key[i];
    }
    cout <<  total;               // sum of weights in MST

    return ans;
}

// by seeing parent array start making the tree

/*
1. Find min key
2. Mark the mst[key]=true
3. Find adj
4. Mark parent[adj]
*/