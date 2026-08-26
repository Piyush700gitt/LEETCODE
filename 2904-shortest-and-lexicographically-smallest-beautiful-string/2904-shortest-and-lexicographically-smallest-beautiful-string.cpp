class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        string ans="";
        int minlen=INT_MAX;
        int left=0,right=0;
        int cnt=0;
        for(right=0;right<n;right++){
            string curr="";
            if(s[right]=='1'){
                cnt++;
            }
            while(cnt==k){
                int len=right-left+1;
                curr=s.substr(left,len);
                if(len<minlen){
                    minlen=len;
                    ans=curr;
                }
                else if(len==minlen){
                    ans=min(ans,curr);
                }
                if(s[left]=='1'){
                    cnt--;
                }
                left++;
                

            }
            
        }
        return ans;
       
        
    }
};