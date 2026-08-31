class Solution {
public:
void helper(vector<int>&nums,int target,int index,int sum,int &ans,int n){
    if(index==n){
    if(sum==target)ans++;
    return;
    }
    helper(nums,target,index+1,sum+nums[index],ans,n);
    helper(nums,target,index+1,sum-nums[index],ans,n);


}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        helper(nums,target,0,0,ans,n);
        return ans;

        
    }
};