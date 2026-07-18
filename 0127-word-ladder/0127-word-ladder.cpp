class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_map<string,int>mpp;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        for(auto &x:wordList){
            mpp[x]++;

        }
        while(!q.empty()){
            string curr=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(curr==endWord)return steps;
            for(int i=0;i<curr.size();i++){
                char temp=curr[i];
                for(char c='a';c<='z';c++){
                    string next=curr;
                    next[i]=c;
                    if(mpp.find(next)!=mpp.end()){
                        q.push({next,steps+1});
                        mpp.erase(next);
                    }

                }
            }
        }
        return 0;
        
        
    }
};