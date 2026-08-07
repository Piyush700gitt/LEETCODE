class Solution {
public:
    vector<array<int,4>> add = {
        {0,0,0,0}, //0
        {0,0,0,0}, //1
        {1,0,0,0}, //2
        {0,1,0,0}, //3
        {2,0,0,0}, //4
        {0,0,1,0}, //5
        {1,1,0,0}, //6
        {0,0,0,1}, //7
        {3,0,0,0}, //8
        {0,2,0,0}  //9
    };

    string s;
    int n;
    int need2, need3, need5, need7;

    unordered_map<long long, bool> memo;

    long long encode(int pos,int r2,int r3,int r5,int r7,int tight){
        long long key = pos;
        key = key * 65 + r2;
        key = key * 45 + r3;
        key = key * 20 + r5;
        key = key * 20 + r7;
        key = key * 2 + tight;
        return key;
    }

    bool dfs(int pos,int r2,int r3,int r5,int r7,bool tight){
        if(pos==n){
            return (r2==0 && r3==0 && r5==0 && r7==0);
        }

        int rem = n-pos;
        if(r2 > 3*rem || r3 > 2*rem || r5 > rem || r7 > rem)
            return false;

        long long key = encode(pos,r2,r3,r5,r7,tight);
        if(memo.count(key)) return memo[key];

        int lim = tight ? (s[pos]-'0') : 1;
        int start = max(1, lim);

        for(int d=start; d<=9; d++){
            bool nt = tight && (d==lim);

            int nr2 = max(0, r2-add[d][0]);
            int nr3 = max(0, r3-add[d][1]);
            int nr5 = max(0, r5-add[d][2]);
            int nr7 = max(0, r7-add[d][3]);

            if(dfs(pos+1,nr2,nr3,nr5,nr7,nt))
                return memo[key]=true;
        }

        return memo[key]=false;
    }

    string build(){
        string ans;
        int r2=need2,r3=need3,r5=need5,r7=need7;
        bool tight=true;

        for(int pos=0; pos<n; pos++){
            int lim = tight ? (s[pos]-'0') : 1;
            int start = max(1, lim);

            for(int d=start; d<=9; d++){
                bool nt = tight && (d==lim);

                int nr2 = max(0, r2-add[d][0]);
                int nr3 = max(0, r3-add[d][1]);
                int nr5 = max(0, r5-add[d][2]);
                int nr7 = max(0, r7-add[d][3]);

                if(dfs(pos+1,nr2,nr3,nr5,nr7,nt)){
                    ans.push_back(char('0'+d));
                    r2=nr2; r3=nr3; r5=nr5; r7=nr7;
                    tight=nt;
                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {
        need2=need3=need5=need7=0;

        while(t%2==0){ need2++; t/=2; }
        while(t%3==0){ need3++; t/=3; }
        while(t%5==0){ need5++; t/=5; }
        while(t%7==0){ need7++; t/=7; }

        if(t!=1) return "-1";

        int originalLen = num.size();

        for(int len=originalLen; len<=originalLen+60; len++){
            n=len;
            memo.clear();

            if(len==originalLen){
                s=num;
            }else{
                s=string(len,'1');
            }

            if(dfs(0,need2,need3,need5,need7,len==originalLen)){
                return build();
            }
        }

        return "-1";
    }
};