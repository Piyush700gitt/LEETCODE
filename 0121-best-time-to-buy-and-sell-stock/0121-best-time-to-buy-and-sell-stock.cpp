class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,-1);
        dp[0]=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>mini){
                dp[i]=max(dp[i-1],(prices[i]-mini));
            }
            else{
                dp[i]=dp[i-1];
                mini=prices[i];
            }

        }
        return dp[n-1];
       


        
        
    }
};