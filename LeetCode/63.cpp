// 63. 不同路径 II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        dp[0][0] = 1;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i > 0 && j > 0){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }else if(i > 0){
                    dp[i][j] = dp[i-1][j];
                }else if(j > 0){
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};