class Solution {
public:
int sumofdigits(int num){
    int sum=0;
    while(num){
        sum+=num%10;
        num=num/10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sumofdigits(nums[i])==i){
                return i;
            }
        }
        return -1;
        
    }
};