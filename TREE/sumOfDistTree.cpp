class Solution {                       //Sum of distances of all nodes to all nodes
public:
    vector<int> ans;
    void dist(vector<int> &child, vector<int> adj[], int i, int parent){                   //for sum of distance from all other nodes
        for(auto x: adj[i]){
            if(parent==x)
            continue;

            ans[x]=ans[i]-child[x]+(child.size()-child[x]);
            dist(child, adj, x, i);
        }
    }
    int dfsRoot(vector<int> adj[], int i, vector<bool> &visited, vector<int> &child, int level, int &sum){  //level will count the level no. of children
        visited[i]=true;
        int children=0;
        sum+=level;                              //for root node, levels is the dist

        for(auto x: adj[i]){
            if(!visited[x])
            children+=dfsRoot(adj, x, visited, child, level+1, sum);
        }
        return child[i]=children+1;              //will return 1 extra children
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> adj[n];
        ans=vector<int>(n, 0);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        vector<int> child(n, 0);                           //no. of children for each node

        int sum=0;
        dfsRoot(adj, 0, visited, child, 0, sum);           //dist from root
        ans[0]=sum;
        dist(child, adj, 0, -1);

        return ans;
    }
};



//https://leetcode.com/problems/sum-of-distances-in-tree/description/?envType=daily-question&envId=2024-04-28