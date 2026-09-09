class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
          ans= max( ans, n-999)+max( ans,n-999999)+max(ans, n-999999999)+max(ans, n-999999999999);
          if ( n==1000000000000000) return ans+1;
          

        return ans;

        
    }
};