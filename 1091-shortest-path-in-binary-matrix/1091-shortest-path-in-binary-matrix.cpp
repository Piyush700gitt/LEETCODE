class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        visited[0][0]=true;
        q.push({{0,0},1});
        int drow[] = {-1,-1,-1,0,0,1,1,1};
        int dcol[] = {-1,0,1,-1,1,-1,0,1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            if(row==n-1 && col==n-1){
                return steps;
            }
            for(int i=0;i<8;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol] && grid[nrow][ncol]==0){
                    visited[nrow][ncol]=true;
                    q.push({{nrow,ncol},steps+1});
                }
            }
            
        }
        return -1;
        
    }
};