class Solution {
public:
    string smallestPalindrome(string s) {
        string ans="";
        int n=s.size();
        vector<int>freq(26,0);
        for(auto &x:s){
            freq[x-'a']++;


        }
        string mid="";
        for(int i=0;i<26;i++){
            int x=freq[i]/2;
            if(freq[i]%2!=0){
                mid=char(i+'a');
            }
            int cnt=0;
            while(cnt<x){
                ans+=char(i+'a');
                cnt++;
            }
        }
        string neww=ans;
        reverse(neww.begin(),neww.end());
        ans=ans+mid+neww;
        return ans;

       
        
        
    }
};