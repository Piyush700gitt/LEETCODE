class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int l=0;
        int s=0;
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                s=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                l=i;
            }
        }
        int left=min(l,s);
        int right=max(l,s);
        return min( min(right+1,n-left), n-right+left+1);
    

        
    }
};