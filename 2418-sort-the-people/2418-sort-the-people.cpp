class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, greater<int>> mpp;
        for(int i=0;i<names.size();i++){
            mpp[heights[i]]=names[i];
        }
        vector<string>ans;
        for(auto &x:mpp){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};