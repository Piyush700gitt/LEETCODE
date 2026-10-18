class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int negg=-1e9;
        
        //dp [row,col,col]]
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, negg)));
        if (n == 1) {
            dp[0][0][0] = grid[0][0];
        } else {
            dp[0][0][m-1] = grid[0][0] + grid[0][m - 1];
        }
        for(int r=1;r<n;r++){
            for(int c1=0;c1<m;c1++){
                for(int c2=0;c2<m;c2++){
                    int cherry=grid[r][c1];
                    if(c1!=c2){
                        cherry+=grid[r][c2];
                    }
                    int best=negg;
                    for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){
                            int prev1=c1+d1;
                            int prev2=c2+d2;
                            if(prev1>=0 && prev1<m && prev2>=0 && prev2<m){
                                best=max(best,dp[r-1][prev1][prev2]);

                            }

                        }
                    }
                    dp[r][c1][c2]=best+cherry; 
                               
            }
        }
    }
    int ans=0;
    for(int c1=0;c1<m;c1++){
        for(int c2=0;c2<m;c2++){
            ans=max(ans,dp[n-1][c1][c2]);
        }
    }
    return ans;
    }
};