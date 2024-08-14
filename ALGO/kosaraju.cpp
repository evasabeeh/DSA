/*
1. sort nodes on finishing time -> topo sort
2. transpose of graph       1 -> 2  then make it 2 -> 1 : change direction
3. apply dfs on sorted nodes
*/

// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// to find number of strongly connected components


class Solution
{
public:
    void topoSort(vector<vector<int>> adj, stack<int> &stk, vector<bool> &vis, int node)
    {
        vis[node] = true;
        for (int j : adj[node])
        {
            if (!vis[j])
                topoSort(adj, stk, vis, j);
        }
        stk.push(node);
    }
    void dfs(vector<int> adj[], vector<bool> &vis, int node)
    {
        vis[node] = true;
        for (int j : adj[node])
        {
            if (!vis[j])
                dfs(adj, vis, j);
        }
    }
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        stack<int> stk;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)          // topo sort
        {
            if (!vis[i])
                topoSort(adj, stk, vis, i);
        }

        vector<int> transpose[V];              // Create a transpose of graph
        for (int i = 0; i < V; i++)
        {
            for (int j : adj[i])
                transpose[j].push_back(i);
        }

        int count = 0;                         // count connected components
        vector<bool> visited(V, false);
        while (!stk.empty())
        {
            int top = stk.top();
            stk.pop();
            if (!visited[top]){
                dfs(transpose, visited, top);
                count++;
            }
        }
        return count;
    }
};
