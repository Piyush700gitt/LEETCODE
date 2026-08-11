class disjoint {
public:
    vector<int> parent, size;

    disjoint(int z) {
        parent.resize(z);
        size.resize(z, 1);
        for (int i = 0; i < z; i++) {
            parent[i] = i;
        }
    }
    int ultimateparent(int curr) {
        if (parent[curr] == curr)
            return curr;
        return parent[curr] = ultimateparent(parent[curr]);
    }
    void unionbysize(int u, int v) {
        u = ultimateparent(u);
        v = ultimateparent(v);
        if (u == v)
            return;
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint ds(n * n);
        int dc[]={0,-1,0,1};
        int dr[]={-1,0,1,0};
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int adj=nr*n+nc;
                        int node=row*n+col;
                        ds.unionbysize(adj,node);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                set<int>st;
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int adj=nr*n+nc;
                        st.insert(ds.ultimateparent(adj));

                    }
                }
                int totalsize=0;
                for(auto &it:st){
                    totalsize+=ds.size[it];

                }
                mx=max(mx,totalsize+1);
            }
        }
        for(int cellno=0;cellno<n*n;cellno++){
            mx=max(mx,ds.size[ds.ultimateparent(cellno)]);

        }
        return mx;


    }
};