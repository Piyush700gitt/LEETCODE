class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> lastindex(m, -1);
        int k = m - 1;

        for (int i = n - 1; i >= 0 && k>= 0; i--) {
            if (word1[i] == word2[k]) {
                lastindex[k] = i;
                k--;
            }
        }

        int j = 0;
        int mismatch = 0;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (j == m) break;

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (mismatch == 0 &&
                     (j == m - 1 || i < lastindex[j + 1])) {

                ans.push_back(i);
                mismatch++;
                j++;
            }
        }

        if (j == m) return ans;
        return {};
    }
};