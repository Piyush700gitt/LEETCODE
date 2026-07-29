class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto &x:edges){
            int src=x[0];
            int dest=x[1];
            int wt=x[2];
            dist[src][dest]=wt;
            dist[dest][src]=wt;

        }
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        // now floyd warshall
        for(int via=0;via<n;via++){
            for(int src=0;src<n;src++){
                for(int dest=0;dest<n;dest++){
                    if(dist[src][via]!=1e9 && dist[via][dest]!=1e9){
                        dist[src][dest]=min(dist[src][dest],dist[src][via]+dist[via][dest]);
                    }
                }
            }
        }
        int mini=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=mini){
                mini=cnt;
                ans=i;
            }
        }
        return ans;



        
    }
};