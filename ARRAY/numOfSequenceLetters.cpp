// https://leetcode.com/problems/letter-tile-possibilities/


class Solution
{
public:
    int count = 0;
    void solve(vector<int> &vis)
    {
        for (int i = 0; i < 26; i++)
        {
            if (vis[i] > 0)
            {
                vis[i]--;
                count++;
                solve(vis); // backtrack
                vis[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles)
    {
        int n = tiles.size();
        vector<int> vis(26, 0);
        for (char c : tiles)
            vis[c - 'A']++;
        solve(vis);
        return count;
    }
};