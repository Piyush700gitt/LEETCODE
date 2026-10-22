class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        // base case if(i==n)retrun 0;
        dp[n][0]=0;
        dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int price=0;
                if(buy==1){
                    int take=-prices[ind]+dp[ind+1][0];
                    int nottake=0+dp[ind+1][1];
                    price=max(take,nottake);
                }
                else{
                    int sold=prices[ind]+dp[ind+2][1];
                    int notsold=0+dp[ind+1][0];
                    price=max(sold,notsold);
                }
                dp[ind][buy]=price;
            }
        }
        return dp[0][1];

        
    }
};