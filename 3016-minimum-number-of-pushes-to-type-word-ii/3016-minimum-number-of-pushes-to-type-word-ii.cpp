class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(auto &c:word){
            freq[c-'a']++;

        }
        int ans=0;
        sort(freq.rbegin(),freq.rend());
        for(int i=0;i<26;i++){
            if(freq[i]==0)return ans;
            ans=ans+freq[i]*(i/8 +1);
            
        }
        return ans;
        
    }
};