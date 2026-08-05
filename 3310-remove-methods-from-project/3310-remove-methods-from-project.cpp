class Solution {
public:
void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&suspicious){
    visited[node]=true;
    suspicious[node]=true;
    for(auto &it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,suspicious);
        }
    }
    
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool>suspicious(n,false);
        vector<bool>visited(n,false);
        vector<vector<int>>adj(n);
        for(auto &x:invocations){
            adj[x[0]].push_back(x[1]);
        }
        dfs(k,adj,visited,suspicious);
        vector<int>ans;
         bool canremove=true;
        for(auto &e : invocations){
            int u=e[0];
            int v=e[1];
            if(!suspicious[u] && suspicious[v]){
                canremove=false;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(canremove==false){
                ans.push_back(i);
            }
            else{
                if(!suspicious[i]){
                    ans.push_back(i);
                }
            }
        }
        return ans;



        
    }
};