#include<bits/stdc++.h>
using namespace std;
                                    //No. of ways to reach to last node from start node in minimal time
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
    }
};
int main(){
    vector<vector<int>> v;
    v.push_back({0, 6, 7});
    v.push_back({0, 1, 2});
    v.push_back({1, 2, 3});
    v.push_back({1, 3, 3});
    v.push_back({6, 3, 3});
    v.push_back({3, 5, 1});
    v.push_back({6, 5, 1});
    v.push_back({2, 5, 1});
    v.push_back({0, 4, 5});
    v.push_back({4, 6, 2});

    Solution obj;
    cout<<obj.countPaths(7, v);
    return 0;
}
