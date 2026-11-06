class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]>mini && nums[i]<maxi){
                cnt++;
            }
        }
        return cnt;
      
    }
};