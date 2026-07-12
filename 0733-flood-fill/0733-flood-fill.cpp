class Solution {
public:
void dfs(vector<vector<int>>& matrix,vector<vector<bool>>&visited,int row,int col,vector<vector<int>>&image,int &color,
int drow[],int dcol[],int &initial){
    int n=matrix.size();
    int m=matrix[0].size();
    visited[row][col]=true;
    image[row][col]=color;
        for(int i=0;i<4;i++){
        int nr=row+drow[i];
        int nc=col+dcol[i];
         if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]==initial && !visited[nr][nc])
        dfs(matrix,visited,nr,nc,image,color,drow,dcol,initial);
        }
      


}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>matrix=image;
        int initial=matrix[sr][sc];
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
         int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        dfs(matrix,visited,sr,sc,image,color,drow,dcol,initial);
        return image;

        
    }
};