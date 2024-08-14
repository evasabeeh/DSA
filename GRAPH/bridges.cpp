// https://www.naukri.com/code360/problems/bridges-in-graph_893026?leftPanelTabValue=PROBLEM

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> adj[], vector<bool> &vis, vector<int> &low, vector<vector<int>> &ans)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (int neigh : adj[node])
    {
        if (neigh == parent)                         // so that we don't keep running in a cycle
            continue;

        if (!vis[neigh])
        {
            dfs(neigh, node, timer, disc, adj, vis, low, ans);
            low[node] = min(low[node], low[neigh]);

            if (low[neigh] > disc[node])             // then it is a bridge
                ans.push_back({node, neigh});
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[neigh]);     // that means there is another edge from where you can reach the node
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    vector<int> adj[v];
    for (auto ee : edges)
    {
        adj[ee[0]].push_back(ee[1]);
        adj[ee[1]].push_back(ee[0]);
    }
    vector<bool> vis(v, false);
    vector<int> disc(v, -1), low(v, -1);       // discovery time; lowest time to reach the node

    vector<vector<int>> ans;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, -1, 0, disc, adj, vis, low, ans);

        if (low[d] > disc[c] || low[c] > disc[d])         // to check if particular edge c-d is a bridge or not
            cout << "Bridge";
    }
    return ans;
}

// O(V+E)
// SC(V)


// articulation point : if(low[neigh] >= disc[node] && parent != -1)