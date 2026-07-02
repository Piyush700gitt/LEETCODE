class Solution {
public:
    string countAndSay(int n) {
        int k=1;
        string ans="1";
        while(k<n){
            string curr="";
            char el=ans[0];
            int cnt=1;

            for(int i=1;i<ans.size();i++){
                if(ans[i]==el){
                    cnt++;
                }
                else{
                    curr+=to_string(cnt);
                    curr+=el;
                    cnt=1;
                    el=ans[i];
                }

            }
            k++;
            curr+=to_string(cnt);
            curr+=el;
            ans=curr;



        }
        return ans;



        
    }
};