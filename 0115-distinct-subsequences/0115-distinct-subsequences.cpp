class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long >>dp(n+1,vector<unsigned long long >(m+1,0));
        for(int i=0;i<=n;i++){
            //mtlbb t string hai hi nhii 
            dp[i][0]=1;
            // kyuki empty string banane ka ek hi tarika h kisiko mt lo
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=0;
            // kuch hai hi nhi toh kisse banaoge? isliyee 0 waysss 

        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};