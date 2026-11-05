class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            int mx = 0;

            for (int len = 1; len <= k && i + len <= n; len++) {

                mx = max(mx, arr[i + len - 1]);
                // max of mx and the new element inckuded after the lenn

                int sum = mx * len + dp[i + len];
                // dp[i+len]-->remaining afterr taking ith indexx

                dp[i] = max(dp[i], sum);
            }
        }

        return dp[0];
    }
};