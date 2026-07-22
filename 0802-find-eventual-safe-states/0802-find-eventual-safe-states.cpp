class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>>adj(v);
        vector<int>degree(v);
        for(int i=0;i<v;i++){
            degree[i]=graph[i].size();
            for(auto &x:graph[i]){
                adj[x].push_back(i);
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<v;i++){
            if(degree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto &it:adj[curr]){
                degree[it]--;
                if(degree[it]==0){
                q.push(it);
                }
            }

        }
        sort(ans.begin(),ans.end());
        return ans;
       
        
       
        
    }
};