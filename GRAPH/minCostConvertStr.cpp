class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<int>> costMat(26, vector<int>(26, INT_MAX));

        for (int i = 0; i < 26; i++)
            costMat[i][i] = 0; // no change

        for (int i = 0; i < original.size(); i++)
            costMat[original[i] - 'a'][changed[i] - 'a'] = min(cost[i], costMat[original[i] - 'a'][changed[i] - 'a']);

        for (int k = 0; k < 26; k++)
        { // indirect change variable
            for (int i = 0; i < 26; i++)
            { // from
                for (int j = 0; j < 26; j++)
                { // to
                    if (costMat[i][k] != INT_MAX && costMat[k][j] != INT_MAX)
                        costMat[i][j] = min(costMat[i][j], costMat[i][k] + costMat[k][j]); // if change char from i to j... either directly change it from i to j or i to k and then k to j
                }
            }
        }
        long long minCost = 0;
        for (int i = 0; i < source.size(); i++)
        {
            int c = costMat[source[i] - 'a'][target[i] - 'a'];

            if (c == INT_MAX) // means char can't be changed to src char
                return -1;

            minCost += c;
        }
        return minCost;
    }
};

// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/