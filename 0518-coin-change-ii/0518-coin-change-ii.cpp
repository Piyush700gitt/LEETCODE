class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        const long long inf = 1e18;

        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){

                long long donttake = dp[i-1][j];

                long long take = 0;

                if(coins[i] <= j){
                    take = dp[i][j - coins[i]];
                }

                dp[i][j] = take + donttake;

                // Prevent intermediate overflow
                if(dp[i][j] > INT_MAX){
                    dp[i][j] = INT_MAX;
                }
            }
        }

        return dp[n-1][amount];
    }
};