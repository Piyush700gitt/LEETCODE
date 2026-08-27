class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int j=n-1;
        int f=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[f]=nums[i];
                f++;
            }
            else{
                ans[j]=nums[i];
                j--;
            }
        }
        return ans;
        
    }
};