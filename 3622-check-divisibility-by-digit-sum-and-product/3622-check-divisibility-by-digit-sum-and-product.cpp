class Solution {
public:
    bool checkDivisibility(int n) {
        int dup=n;
        int sum=0;
        int prod=1;
        while(dup){
            int rem=dup%10;
            sum+=rem;
            prod=prod*rem;
            dup=dup/10;

        }
        int final=sum+prod;
        return n%final==0;

    
        
    }
};