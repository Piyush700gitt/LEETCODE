class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &x:times){
            adj[x[0]].push_back({x[1],x[2]});// dest,time
        }
      priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
      vector<int>dist(n+1,1e9);
      dist[k]=0;
      pq.push({0,k});
      while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int dis=it.first;
        int node=it.second;
        if(dist[node]<dis)continue;
        for(auto &ad:adj[node]){
            int wt=ad.second;
            int dest=ad.first;
            if(dist[dest]>dis+wt){
                dist[dest]=dis+wt;
                pq.push({dist[dest],dest});
            }
        }


      }
      int maxi=dist[1];
      for(int i=2;i<dist.size();i++){
        maxi=max(maxi,dist[i]);
      }
      if(maxi==1e9)return -1;
      return maxi;

      
    }
};