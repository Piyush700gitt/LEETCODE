class Solution {
public:
    bool pred(string a, string b) {
        // len(a)>len(b);;
        int i = 0, j = 0;
        while (i < a.size()) {
            if (j < b.size() && a[i] == b[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == b.size();
    }

    int longestStrChain(vector<string>& words) {
        // comparator to sort the array acc to size ();

        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size()==words[j].size()+1){
                    if(pred(words[i],words[j])==true){
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};