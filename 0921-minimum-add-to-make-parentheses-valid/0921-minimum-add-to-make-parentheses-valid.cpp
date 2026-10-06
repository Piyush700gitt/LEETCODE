class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt = n;
        stack<char> st;
        if (s[0] == ')' || s[0] == '(') {
            st.push(s[0]);
        }
        if (st.empty()) {
            return 0;
        }

        for (int i = 1; i < n; i++) {
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if (st.top() == '(' && s[i] == ')') {
                cnt = cnt - 2;
                st.pop();
           
            } else {
                st.push(s[i]);
            }
        }
        return cnt;
    }
};