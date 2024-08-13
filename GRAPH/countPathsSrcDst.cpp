// https://www.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/1


class Solution
{
public:
    // Function to count paths between two vertices in a directed graph.
    void dfs(int src, int dst, vector<bool> &vis, vector<int> adj[], int &paths)
    {
        if (src == dst)
        {                                     // destination found
            paths++;
            return;
        }
        for (int i : adj[src])
        {
            if (!vis[i])
            {
                vis[i] = true;
                dfs(i, dst, vis, adj, paths);
                vis[i] = false;               // backtrack
            }
        }
    }
    int countPaths(int V, vector<int> adj[], int source, int destination)
    {
        vector<bool> vis(V, false);
        int paths = 0;
        vis[source] = true;
        dfs(source, destination, vis, adj, paths);

        return paths;
    }
};