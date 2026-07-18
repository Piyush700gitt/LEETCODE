class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        //rowws
        for(int i=0;i<m;i++){
            if(!visited[0][i] && grid[0][i]==1){
                visited[0][i]=true;
                q.push({0,i});
            }
            if(!visited[n-1][i] && grid[n-1][i]==1){
                visited[n-1][i]=true;
                q.push({n-1,i});
            }
        }
        //columnsss
        for(int i=0;i<n;i++){
            if(!visited[i][0] && grid[i][0]==1){
                visited[i][0]=true;
                q.push({i,0});
            }
            if(!visited[i][m-1]  && grid[i][m-1]==1){
                visited[i][m-1]=true;
                q.push({i,m-1});
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    visited[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};