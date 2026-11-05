class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int maxi=INT_MIN;
            int maxSum=INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                maxi=max(maxi,nums[j]);
                int cost=(j-i+1)*maxi+dp[j+1];
                maxSum=max(maxSum,cost);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};