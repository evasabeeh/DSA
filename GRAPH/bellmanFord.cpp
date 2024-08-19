class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 1; i < V; i++)
        { // n-1 times
            for (int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                if (dist[u] != 1e8 && (dist[u] + w) < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
        // check for negative cycle
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[u] != 1e8 && (dist[u] + w) < dist[v])                // if negative cycle exists
                return {-1};
        }
        return dist;
    }
};

// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1