class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        /// baseee casee
        // repliactee the first row and 1st colmn
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
        }
        for(int r=1;r<n;r++){
            for(int c=1;c<m;c++){
                if(matrix[r][c]==1){
                int up=dp[r-1][c];
                int left=dp[r][c-1];
                int diag=dp[r-1][c-1];
                dp[r][c]=1+min({up,left,diag});
            }
            else{
                dp[r][c]=0;
            }
        }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=dp[i][j];
            }
        }
        return sum;
        
    }
};