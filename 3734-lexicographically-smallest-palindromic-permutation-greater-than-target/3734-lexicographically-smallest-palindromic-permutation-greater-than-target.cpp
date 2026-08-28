class Solution {
public:

    string makePalindrome(string &half, char mid, int n) {
        string ans = half;

        if (n % 2)
            ans += mid;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int m = n / 2;

        // Frequency of characters
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // Find middle character
        char mid = '#';
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        // Cannot form a palindrome
        if (odd > 1)
            return "";

        // We only need half the characters
        vector<int> cnt(26);

        for (int i = 0; i < 26; i++)
            cnt[i] = freq[i] / 2;

        string best = "";

        /*
            DFS constructs the first half.

            relation:
            0 -> still equal to target
            1 -> already greater than target
        */

        function<bool(int, bool, string&)> dfs =
            [&](int pos, bool greater, string &half) -> bool {

            if (pos == m) {

                string p = makePalindrome(half, mid, n);

                if (p > target) {
                    best = p;
                    return true;
                }

                return false;
            }

            int start = 0;

            if (!greater)
                start = target[pos] - 'a';

            for (int c = start; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                bool newGreater = greater || (c > target[pos] - 'a');

                // If we're equal so far and choose a smaller char,
                // this branch is invalid.
                if (!greater && c < target[pos] - 'a')
                    continue;

                cnt[c]--;
                half.push_back(char('a' + c));

                if (dfs(pos + 1, newGreater, half))
                    return true;

                half.pop_back();
                cnt[c]++;
            }

            return false;
        };

        string half;

        dfs(0, false, half);

        return best;
    }
};