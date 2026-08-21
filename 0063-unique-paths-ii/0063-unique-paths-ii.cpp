class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        if(obstacleGrid[0][0] == 1)
            return 0;

        dp[0][0] = 1;


        for(int j = 1; j < m; j++) {
            if(obstacleGrid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }


        for(int i = 1; i < n; i++) {
            if(obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }

        for(int row = 1; row < n; row++) {
            for(int col = 1; col < m; col++) {

                if(obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }

                dp[row][col] =
                    dp[row-1][col] + dp[row][col-1];
            }
        }

        return dp[n-1][m-1];
    }
};