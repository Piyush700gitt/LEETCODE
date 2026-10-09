class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size();
        int cnt = 0;
// (-->)) chiyee consecutivee
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push('(');
            }

            else {
               
                if (i + 1 < n && s[i + 1] == ')') {

                    if (!st.empty()) {
                        st.pop();
                    }
                    else {
                       
                        cnt++;
                    }

                    i++; 
                }

                else {
                  
                    cnt++;

                    if (!st.empty()) {
                        st.pop();
                    }
                    else {
                       
                        cnt++;
                    }
                }
            }
        }

        
        cnt += 2 * st.size();

        return cnt;
    }
};