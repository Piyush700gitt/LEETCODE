class Solution {
public:
    long long sumAndMultiply(int n) {
        long long  temp = 0;
        long long  sum = 0;
        long long place=10;
        while (n) {
            long long  rem = n % 10;
            if (rem != 0) {
                if(temp==0){
                    temp=rem;
                }
                else{
                temp=(rem*place)+temp;
                place=place*10;
                }

                sum=sum+rem;
            }
            
            n=n/10;

        }
        return temp*sum;
    }
    };