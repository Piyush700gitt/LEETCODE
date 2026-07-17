class Solution {
public:
int gcd(long long  x,long long y){
    if(x==0){
        return y;
    }
    else if(y==0)return x;
    else if(x>=y){
        return gcd(x%y,y);
    }
    else if(y>x){
        return gcd(x,y%x);
    }
    return -1;

}

    long long gcdSum(vector<int>& nums) {
        long long  maxi=nums[0];
        vector<long long>prefixgcd;
        prefixgcd.push_back(maxi);
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi,1LL*nums[i]);
            long long  topush=gcd(nums[i],maxi);
            prefixgcd.push_back(topush);

        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0,j=prefixgcd.size()-1;
        long long  sum=0;
        while(i<j){
            sum=sum+gcd(prefixgcd[i],prefixgcd[j]);
            i++;
            j--;

        }
        return sum;
        
    }
};