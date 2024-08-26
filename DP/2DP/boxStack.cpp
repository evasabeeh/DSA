// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

class Solution
{
public:
    bool check(vector<int> &putBox, vector<int> &baseBox)
    {
        if (baseBox[0] >= putBox[0] && baseBox[1] >= putBox[1] && baseBox[2] >= putBox[2])
            return true;
        else
            return false;
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &v : cuboids)
            sort(v.begin(), v.end());

        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();                      // LIS Algo
        vector<int> curr(n + 1, 0), next(n + 1, 0);

        for (int currIdx = n - 1; currIdx >= 0; currIdx--)
        {
            for (int prevIdx = currIdx - 1; prevIdx >= -1; prevIdx--)
            {
                int take = 0, notTake = 0;

                // take
                if (prevIdx == -1 || check(cuboids[prevIdx], cuboids[currIdx]))
                    take = cuboids[currIdx][2] + next[currIdx + 1];

                notTake = next[prevIdx + 1];

                curr[prevIdx + 1] = max(take, notTake);
            }
            next = curr;
        }
        return next[0];
    }
};

/*
1. Sort all dimensions for every cuboid because it is not said that it can not be rotated
2. Sort all cuboids by their width in asc order
*/

/* 
1. Sort all dimensions for every cuboid because it is not said that it can not be rotated 
2. Sort all cuboids by their width in asc order
3. Use LIS
*/