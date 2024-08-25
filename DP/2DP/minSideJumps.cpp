// https://leetcode.com/problems/minimum-sideway-jumps/

class Solution
{
public:
    int solve(int lane, int idx, vector<int> &obstacles, vector<vector<int>> &dp)
    {
        if (idx == obstacles.size() - 1) // reached destination, last position in any lane
            return 0;

        if (dp[lane][idx] != -1)
            return dp[lane][idx];

        if (obstacles[idx + 1] != lane) // no need to change the lane
            return solve(lane, idx + 1, obstacles, dp);
        else
        {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (i != lane && obstacles[idx] != i) // lane which don't have obstacle, move to that
                    ans = min(ans, 1 + solve(i, idx + 1, obstacles, dp));
            }
            dp[lane][idx] = ans;
        }
        return dp[lane][idx];
    }
    int minSideJumps(vector<int> &obstacles)
    {
        vector<vector<int>> dp(4, vector<int>(obstacles.size() + 1, -1)); // 2D dp because two parameters: lane and idx is changing
        return solve(2, 0, obstacles, dp);                                // start lane is 2 and position is 0
    }
};