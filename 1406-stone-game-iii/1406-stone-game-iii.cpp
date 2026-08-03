class Solution {
public:
    vector<int> dp;

    int solve(int i, vector<int>& stoneValue, int n) {
        if (i >= n) return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int score = 0;
        int ans = INT_MIN;

        for (int j = 0; j < 3 && i + j < n; j++) {
            score += stoneValue[i + j];
            ans = max(ans, score - solve(i + j + 1, stoneValue, n));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int temp = solve(0, stoneValue, n);

        if (temp > 0) return "Alice";
        if (temp < 0) return "Bob";
        return "Tie";
    }
};