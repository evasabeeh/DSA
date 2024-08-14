
class Solution
{
public:
    void dfs(int node, int parent, int timer, vector<int> &disc,
             vector<int> adj[], vector<bool> &vis, vector<int> &low,
             set<int> &st)
    {
        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for (int neigh : adj[node])
        {
            if (neigh == parent) // so that we don't keep running in a cycle
                continue;

            if (!vis[neigh])
            {
                dfs(neigh, node, timer, disc, adj, vis, low, st);
                low[node] = min(low[node], low[neigh]);

                if (low[neigh] >= disc[node] && parent != -1)        // it is an articulation point
                    st.insert(node);

                child++;
            }
            else
            {
                // back edge
                low[node] = min(low[node], disc[neigh]);
            }
            if (parent == -1 && child > 1)                  // root node 
                st.insert(node);
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> disc(V, -1), low(V, -1);
        set<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                dfs(i, -1, 0, disc, adj, vis, low, st);
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
