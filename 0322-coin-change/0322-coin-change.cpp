class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        const int inf = 1e9;

        vector<vector<int>> dp(n, vector<int>(amount + 1, inf));

        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }

        
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){

                int donttake = dp[i-1][j];

                int take = inf;

                if(coins[i] <= j){
                    take = 1 + dp[i][j-coins[i]];
                }

                dp[i][j] = min(take, donttake);
            }
        }

        if(dp[n-1][amount] == inf)
            return -1;

        return dp[n-1][amount];
    }
};