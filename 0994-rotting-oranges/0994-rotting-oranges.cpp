class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]==2){
                    q.push({{r,c},0});
                    visited[r][c]=true;
                }
            }

        }
        int time=0;
        int row[]={-1,0,+1,0};
        int col[]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+row[i];
                int ncol=c+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                 visited[nrow][ncol]==false && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol]=true;
                 }
            }
        }
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(visited[r][c]==false && grid[r][c]==1){
                    return -1;
                }
            }
        }
        return time;

        
    }
};