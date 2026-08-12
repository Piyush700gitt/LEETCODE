class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int right=0;
        int left=0;
        int maxi=INT_MIN;
        unordered_map<int,int>mpp;
        for(right=0;right<n;right++){
            mpp[nums[right]]++;
            while(mpp[nums[right]]>k){
                mpp[nums[left]]--;
                left++;
            }
            maxi=max(maxi,right-left+1);

        }
        return maxi;
    }
};