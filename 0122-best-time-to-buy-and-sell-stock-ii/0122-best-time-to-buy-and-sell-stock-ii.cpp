class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ans(prices);
        sort(ans.begin(),ans.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ans[i]==prices[i]){
                cnt++;
            }
        }
        if(cnt==n){
            return (prices[n-1]-prices[0]);
        }
        vector<int>dp(n,-1);
        dp[0]=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>mini){
                dp[i]=dp[i-1]+(prices[i]-mini);
                mini=prices[i];
            }
            else{
                dp[i]=dp[i-1];
                mini=prices[i];
            }
        }
        return dp[n-1];
        
    }
};