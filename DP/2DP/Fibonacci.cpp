// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int mx = 0;
        for (int curr = 2; curr < n; curr++)
        { // we will find previous two numbers that sum upto current number making it a fibonacci number
            int left = 0, right = curr - 1;

            while (left < right)
            { // now find two numbers which sum upto target
                int sum = arr[left] + arr[right];
                if (sum < arr[curr])
                    left++;
                else if (sum > arr[curr])
                    right--;
                else
                {
                    dp[right][curr] = dp[left][right] + 1;
                    mx = max(mx, dp[right][curr]);
                    right--;
                    left++;
                }
            }
        }
        if (mx == 0)
            return 0;
        else
            return mx + 2; // then first two numbers will automatically be fibonacci
    }
};