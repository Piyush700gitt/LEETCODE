class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]>0){
                    visited[i][j]=true;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    long long  sum=0;
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        sum+=grid[row][col];
                        for(int k=0;k<4;k++){
                            int nrow=row+drow[k];
                            int ncol=col+dcol[k];
                            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>0 && 
                            !visited[nrow][ncol]){
                                visited[nrow][ncol]=true;
                                q.push({nrow,ncol});
                            }
                        }
                    }
                    if(sum%k==0)cnt++;
                }
            }
        }
        return cnt;
        
    }
};