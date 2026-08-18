class Solution {
public:
int dp(vector<int>&nums,int start,int end){
    vector<int>dp(end-start+1,-1);
    dp[0]=nums[start];
    dp[1]=max(nums[start],nums[start+1]);
    for(int i=2;i<dp.size();i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[start+i]);
    }
    return dp[end-start];

}
    int rob(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        ans=max(dp(nums,0,n-2),dp(nums,1,n-1));
        return ans;


        
    }
};