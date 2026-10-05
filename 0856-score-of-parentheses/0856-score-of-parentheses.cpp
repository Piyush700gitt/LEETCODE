class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int cnt=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else{
                cnt--;
                if(s[i-1]=='('){
                    ans+=pow(2,cnt);
                }
            }
        }
        return ans;
       
    }
};