class Solution {
public:
    bool valid(int r,int c,int m,int n){
        return (r>=0&&r<m&&c>=0&&c<n);
    }
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].length();
        vector<vector<int>> id(m, vector<int>(n, -1));
        
        int totall = 0;
        int sr, sc;
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                   sr=i,sc=j;
                }
                if(classroom[i][j]=='L'){
                    id[i][j]=totall;
                    totall++;
                }
            }
        }
       
       int fullMask=(1<<totall)-1;
       queue<tuple<int,int,int,int>>q;
       q.push({sr,sc,energy,0});

       vector<vector<vector<vector<bool>>>>vis(m,vector<vector<vector<bool>>>(n,
       vector<vector<bool>>(energy+1,
       vector<bool>(1<<totall,false))));
        vis[sr][sc][energy][0]=true;
        int ans=0;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c,curr,mask]=q.front();
                q.pop();

                if(mask==fullMask)return ans;

                if(curr==0)continue;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(!valid(nr,nc,m,n))continue;
                    if(classroom[nr][nc]=='X')continue;

                    int newEnergy=curr-1;
                    int newMask=mask;

                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }


                    if(classroom[nr][nc]=='L'){
                        newMask|=(1<<id[nr][nc]);
                    }
                    if(!vis[nr][nc][newEnergy][newMask]){
                        vis[nr][nc][newEnergy][newMask]=true;
                        q.push({nr,nc,newEnergy,newMask});
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};