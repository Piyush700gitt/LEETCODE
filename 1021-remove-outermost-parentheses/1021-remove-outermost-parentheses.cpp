class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(cnt != 0) ans.push_back(s[i]);
                cnt++;
            }
            else {
                cnt--;
                if(cnt != 0) ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
