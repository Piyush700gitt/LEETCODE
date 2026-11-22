class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(s[i]=='a' && s[j]=='b'){
                    return false;
                }
            }
        }
        return true;
        
    }
};