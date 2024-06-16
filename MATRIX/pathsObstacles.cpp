#include<bits/stdc++.h>
using namespace std;
                       //count paths to reach last cell in a grid having obstacles
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        bool flag=false;
        for(int i=0;i<m;i++){                               //initialising paths to reach first row cells
            if(obstacleGrid[i][0]==1||flag==true){
                flag=true;
                continue;
            }
            dp[i][0]=1;
        }
        flag=false;
        for(int i=0;i<n;i++){                               //initialising paths to reach first col cells
            if(obstacleGrid[0][i]==1||flag==true){
                flag=true;
                continue;
            }
            dp[0][i]=1;
        }

        if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1)         //if start cell has an obstacle, then no path is possible
        return 0;

        if(m-1==0||n-1==0)                                  //if destination cell has an obstacle, then it can not be reached
        return dp[m-1][n-1];

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution obj;
    vector<vector<int>> vec;
    vec.push_back({0, 0});
    vec.push_back({0, 0});
    vec.push_back({1, 0});
    cout<<obj.uniquePathsWithObstacles(vec);
}