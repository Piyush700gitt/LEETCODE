class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mpp;
        vector<int>v=arr;
        int rank=1;
        sort(v.begin(),v.end());
        for(auto &x :v){
            if(mpp.find(x)==mpp.end()){
            mpp[x]=rank;
            rank++;
        }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;

        
        
        

        
        
    }
};