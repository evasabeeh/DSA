// https://leetcode.com/problems/redundant-connection/
// Union set and Disjoint set

class Solution
{
public:
    int findParent(int node, vector<int> &parent)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }
    void unionSet(int u, int v, vector<int> &parent,
                  vector<int> &rank)
    {
        int x = findParent(u, parent);
        int y = findParent(v, parent);

        if (rank[x] < rank[y])
            parent[x] = y;
        else if (rank[y] < rank[x])
            parent[y] = x;
        else
        {
            parent[y] = x;
            rank[x]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0); // one extra edge

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0], v = edges[i][1];

            int x = findParent(u, parent);
            int y = findParent(v, parent);

            if (x == y) // if same component
                return edges[i];

            unionSet(u, v, parent, rank);
        }
        return {};
    }
};