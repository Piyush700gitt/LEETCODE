class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string ans = "";
        stack<char> st;
        vector<int> last(26);

        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<bool> visited(26, false);
        st.push(s[0]);
        visited[s[0] - 'a'] = true;
        int i = 1;

        while (i < n) {

            if (!visited[s[i] - 'a']) {

                while (!st.empty() && st.top() > s[i] &&
                       last[st.top() - 'a'] > i) {

                    visited[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(s[i]);
                visited[s[i] - 'a'] = true;
            }

            i++;
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};