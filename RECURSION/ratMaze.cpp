#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(vector<vector<int>> &maze, int n, int x, int y, vector<vector<bool>> vis){
        if (x >= n || y >= n || x<0 || y<0 || vis[x][y] || maze[x][y] == 0)
            return false;

            return true;
    } 
    
    void solve(vector<vector<int>> &maze, int n, int x, int y, vector<vector<bool>> vis, vector<string> &ans, string &path)
    {
        if(x==n-1 && y==n-1){               // destination reached
            ans.push_back(path);
            return;
        }
        vis[x][y]=true;                    // reached x,y

        if(isSafe(maze, n, x-1, y, vis)){
            path.push_back('U');
            solve(maze, n, x-1, y, vis, ans, path);
            path.pop_back();               // backtrack
        }
        if (isSafe(maze, n, x + 1, y, vis))
        {
            path.push_back('D');
            solve(maze, n, x + 1, y, vis, ans, path);
            path.pop_back(); // backtrack
        }
        if (isSafe(maze, n, x, y - 1, vis))
        {
            path.push_back('L');
            solve(maze, n, x, y - 1, vis, ans, path);
            path.pop_back(); // backtrack
        }
        if (isSafe(maze, n, x, y + 1, vis))
        {
            path.push_back('R');
            solve(maze, n, x, y + 1, vis, ans, path);
            path.pop_back(); // backtrack
        }

        vis[x][y]=false;                    // backtrack -> mark unvisited
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        if(m[0][0]==0)
        return {};

        vector<string> ans;
        string path = "";
        vector<vector<bool>> vis(n, vector<bool> (n, false));

        solve(m, n, 0, 0, vis, ans, path);
        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans=s.findPath(m, 4);
    for(string s: ans)
    cout<<s<<" ";
}

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1