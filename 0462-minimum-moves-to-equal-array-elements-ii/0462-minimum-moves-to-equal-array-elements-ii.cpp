class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        int avg=nums[n/2];
        for(int i=0;i<n;i++){
            if(nums[i]==avg)continue;
            cnt+=(abs(nums[i]-avg));
        }
        return cnt;
        
    }
};