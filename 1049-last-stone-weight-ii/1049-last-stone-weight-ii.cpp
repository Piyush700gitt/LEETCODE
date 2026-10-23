class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        // to minimise (s1-s2);
        // s2=total-s1;
        //to minimise|(2s1-T)|
        // it will be minimum when s1 is colse to T/2
        // problem:fidn a subset whose sum is close to T/2;
        int sum=accumulate(stones.begin(),stones.end(),0);
        int target=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(target>=stones[0]){
            dp[0][stones[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(j>=stones[i]){
                    take=dp[i-1][j-stones[i]];
                }
                dp[i][j]=take|| nottake;

            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<=target;i++){
            if(dp[n-1][i])
            maxi=max(maxi,i);
        }
        return sum-2*maxi;

        
        
    }
};