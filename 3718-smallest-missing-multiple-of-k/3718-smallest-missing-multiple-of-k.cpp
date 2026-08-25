class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(auto &x:nums){
            mpp[x]++;
        }
        int maxi=*max_element(nums.begin(),nums.end());
        maxi=maxi+2;
        for(int i=1;i<=maxi;i++){
            if(mpp.find(k*i)!=mpp.end()){
                continue;
            }
            else{
                return k*i;
            }
        }
        return -1;
        
       
        
    }
};