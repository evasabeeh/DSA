class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inc(n, 0);
        vector<int> vec;
        for(int i=0;i<edges.size();i++){     //no. of incoming edges
            inc[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(inc[i]==0)                //0 incoming edge means it can't be reached by any other edge
            vec.push_back(i);
        }
        return vec;
    }
};