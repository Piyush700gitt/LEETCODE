class Solution {
public:
void bfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int i,int j){
    int n=grid.size();
    int m=grid[0].size();
    visited[i][j]=true;
    queue<pair<int,int>>q;
    q.push({i,j});
    int drows[]={-1,0,1,0};
    int dcols[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int x=0;x<4;x++){
        int nrow=row+drows[x];
        int ncol=col+dcols[x];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
            q.push({nrow,ncol});
            visited[nrow][ncol]=true;
        }

    }



}
}

    int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int cnt=0;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(!visited[r][c] && grid[r][c]=='1'){
                bfs(grid,visited,r,c);
                cnt++;
            }
        }

    }
    return cnt;

        
    }
};