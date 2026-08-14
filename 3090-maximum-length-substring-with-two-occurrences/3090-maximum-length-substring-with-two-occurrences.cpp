class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int left=0,right=0;
        int cnt=0;
        for(right=0;right<s.size();right++){
            freq[s[right]-'a']++;
            while(freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;

            }
            cnt=max(cnt,right-left+1);

        }
        return cnt;

        
    }
};