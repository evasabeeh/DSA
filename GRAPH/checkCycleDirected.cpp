
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int node, vector<bool> &dfsVis, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = true;
        dfsVis[node] = true;

        for (int j : adj[node])
        {
            if (!vis[j])
            {
                if (checkCycle(j, dfsVis, vis, adj))
                    return true;
            }
            else if (dfsVis[j] == true)
                return true;
        }
        dfsVis[node] = false;                    // for directed, unmark this node
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<bool> dfsVis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, dfsVis, vis, adj))
                    return true;
            }
        }
        return false;
    }
};
