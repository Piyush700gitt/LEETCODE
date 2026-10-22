class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // dp[ind][buy][cap];
        // base casee 1 --> if(i==n)retrun 0;
        // means cap and buy should be anything;
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                dp[n][i][j]=0;
            }
        }
        // base casee 2 --> if(cap==0)return 0;
        // means ind and buy can be anythinning;;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=1;j++){
                dp[i][j][0]=0;
            }
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    long long price=0;
                    if(buy==1){
                        int take=-prices[ind]+dp[ind+1][0][cap];
                        int nottake=0+dp[ind+1][1][cap];
                        price=max(take,nottake);
                    }
                    else{
                        int sold=prices[ind]+dp[ind+1][1][cap-1];
                        int notsold=0+dp[ind+1][0][cap];
                        price=max(sold,notsold);
                    }
                    dp[ind][buy][cap]=price;

                
                }
            }
        }
        return dp[0][1][2]; 
       
        
    }
};