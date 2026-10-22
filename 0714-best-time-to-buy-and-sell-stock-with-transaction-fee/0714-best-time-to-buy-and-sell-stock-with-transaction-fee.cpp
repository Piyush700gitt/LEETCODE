class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        // dp[ind][buy];
        // base case if(i==n)retunn 0;
        for(int i=0;i<=1;i++){
            dp[n][i]=0;
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int price=0;
                if(buy==1){
                    int take=-prices[ind]+dp[ind+1][0];
                    int nottake=0+dp[ind+1][1];
                    price=max(take,nottake);
                }
                else{
                    int sold=prices[ind]+dp[ind+1][1];
                    int notsold=0+dp[ind+1][0];
                    price=max(sold-fee,notsold);
                }
                dp[ind][buy]=price;
            }
        }
        return dp[0][1];
        

        
    }
};