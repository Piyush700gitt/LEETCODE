class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
        pq.push({0,{0,0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!pq.empty()){
            int dis=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

    if (row == n - 1 && col == m - 1)
        return dis;

            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int wt=abs(heights[nrow][ncol]-heights[row][col]);
                    int neweffort=max(dis,wt);
                    if(neweffort<effort[nrow][ncol]){
                        effort[nrow][ncol]=neweffort;
                        pq.push({neweffort,{nrow,ncol}});
                    }

                }
            }

        }
        return  -1;              

            
    }
};