// https://www.naukri.com/code360/problems/minimum-spanning-tree_631769

#include <bits/stdc++.h>
bool comp(vector<int> &a, vector<int> &b)                      // sort edges according to weight
{
    return a[2] < b[2];
}
int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)                                  // self parent
        return node;

    return parent[node] = findParent(parent[node], parent);    // path compression for parent
                               // 1->2->3 then 1's ultimate parent is 3 => path compression
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{                                                              // Union by Rank
    int x = findParent(u, parent);
    int y = findParent(v, parent);

    if (rank[x] < rank[y])                                     // so that tree's depth is maintained
        parent[x] = y;
    else if (rank[y] < rank[x])
        parent[y] = x;
    else
    {
        parent[y] = x;
        rank[x]++;
    }
}
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), comp);
    int total = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(edges[i][0], parent);
        int v = findParent(edges[i][1], parent);
        int w = edges[i][2];

        if (u != v)                           // that means different component
        {
            total += w;                       // minimum weight of MST
            unionSet(u, v, parent, rank);
        }
    }
    return total;
}

/*
1. make sorted list of {wt, u, v} acc to wt
2. process one by one wts
3. if u and v belong to same component, ignore
4. if not, make union set
*/