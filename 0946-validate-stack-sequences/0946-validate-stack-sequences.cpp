class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;

        for (int x : pushed) {
            st.push(x);

            while (!st.empty() && idx < popped.size() &&
                   st.top() == popped[idx]) {
                st.pop();
                idx++;
            }
        }

        return st.empty();
    }
};