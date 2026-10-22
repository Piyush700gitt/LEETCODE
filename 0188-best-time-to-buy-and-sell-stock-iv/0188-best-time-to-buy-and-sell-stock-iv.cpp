class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // dp[ind][buy][k];
        // base casee 1 if(ind==n)retrun 0;(here buy and k can be anything)
        // base cade 2 if(k==0)return 0,(here ind and buyy can be anything)
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<k;cap++){
                dp[n][buy][cap]=0;
            }
        }
        for(int ind=0;ind<n;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0]=0;
            }
        }
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
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
        return dp[0][1][k];
        
        
    }
};