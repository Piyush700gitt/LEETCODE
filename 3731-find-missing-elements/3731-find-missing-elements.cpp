class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto &x:nums){
            st.insert(x);
        }
        vector<int>ans;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=mini;i<=maxi;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }

        }
        return ans;
       
       
        
    }
};