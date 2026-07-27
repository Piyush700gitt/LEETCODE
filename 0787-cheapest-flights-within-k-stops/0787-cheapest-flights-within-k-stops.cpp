class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});

        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;

        //cost node stops
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k)continue;
            
            for(auto &x:adj[node]){
                int adjnode=x.first;
                int wt=x.second;
                if(dist[adjnode]>cost+wt && stops<=k){
                    dist[adjnode]=cost+wt;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }

        }
        if(dist[dst]==1e9)return-1;
        return dist[dst];
    

        
    }
};