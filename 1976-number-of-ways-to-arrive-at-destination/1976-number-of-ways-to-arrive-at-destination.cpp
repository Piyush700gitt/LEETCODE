class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> pq;
        vector<long long >ways(n,0);
        vector<long long >dist(n,LLONG_MAX);
        int mod=int(1e9+7);
        //dist,node
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            long  dis=pq.top().first;
            long long  node=pq.top().second;
            pq.pop();
            if(dis>dist[node])continue;
            for(auto &x:adj[node]){
                long long  dest=x.first;
                long long  wt=x.second;
                /// pehli baar is distance ke sath pahucha hh 
                if(dist[dest]>dis+wt){
                    dist[dest]=dis+wt;
                    ways[dest]=ways[node];
                    pq.push({dist[dest],dest});
                }
                else if(dist[dest]==dis+wt){
                    // dobara usi distance ke sath aaya h
                    ways[dest]=(ways[dest]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};