class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int j=nums[i];
            int req=target-j;
            if(mpp.find(req)!=mpp.end()){
                return{mpp[req],i};
            }
            mpp[j]=i;//j ko is i index pr dekha gya thaa
            }
            return {};
          }

    
          

};