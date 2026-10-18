class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
        dp[0][i]=matrix[0][i];}
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left=INT_MAX;
                int right=INT_MAX;
                if(j-1>=0){
                 left=matrix[i][j]+dp[i-1][j-1];}
                if((j+1)>=0 && (j+1)<n){
                 right=matrix[i][j]+dp[i-1][j+1];
                }
                int down=matrix[i][j]+dp[i-1][j];
                dp[i][j]=min(left,min(right,down));
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);

        }
        return mini;
       
        

        
    }
};