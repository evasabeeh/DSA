class Solution {
public:                            // space and time: O(n^2)
    int solve(vector<vector<int>> &matrix, int n, int row, int col, vector<vector<int>> &dp){
        if(row==0 && col>=0 && col<n)         //path is completed
        return matrix[row][col];

        if(col>=n || col<0)                   //out of range
        return INT_MAX;

        if(dp[row][col]!=INT_MAX)             // means the result already computed
        return dp[row][col];

        return dp[row][col]=matrix[row][col]+min(solve(matrix, n, row-1, col+1, dp), min(solve(matrix, n, row-1, col, dp), solve(matrix, n, row-1, col-1, dp)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, INT_MAX));

        int ans=INT_MAX;
        for(int i=0;i<n;i++)                               //from last row we start computing, bottom to up approach
        ans=min(ans, solve(matrix, n, n-1, i, dp));        

        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix={{2,1,3},{6,5,4},{7,8,9}};
    cout<<s.minFallingPathSum(matrix);
}


https://leetcode.com/problems/minimum-falling-path-sum/description/