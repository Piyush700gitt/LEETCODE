class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>ans=grid;
        while(cnt<k){
            for(int i=0;i<=n-1;i++){
                for(int j=0;j<m-1;j++){
                    ans[i][j+1]=grid[i][j];
                }
            }
            ans[0][0]=grid[n-1][m-1];
            for(int i=0;i<n-1;i++){
                ans[i+1][0]=grid[i][m-1];
            }
            cnt++;
            grid=ans;

        }
        return ans;
        
    }
};