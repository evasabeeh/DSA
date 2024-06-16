class Solution {
public:                                           // root values which can give minimum height tree

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0)
        return {0};
        
        vector<int> adj[n];
        vector<int> d(n, 0);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            d[e[0]]++;
            d[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(d[i]==1)
            q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            ans.clear();

            while(size--){
                int x=q.front();
                q.pop();
                ans.push_back(x);
                
                for(int j: adj[x]){
                    d[j]--;
                    if(d[j]==1)
                    q.push(j);
                }
            }
        }
        return ans;
    }
};



https://leetcode.com/problems/minimum-height-trees/description/?envType=daily-question&envId=2024-04-23