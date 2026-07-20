class Solution {
public:
bool dfs(int curr,int colour,vector<int>&color,vector<vector<int>>&graph){
    color[curr]=colour;
    for(auto x:graph[curr]){
        if(color[x]==-1){
             if(dfs(x,!colour,color,graph)==false)return false;
        }
        else if(color[x]==colour){
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,graph)==false)return false;
            }
        }
        return true;

        
    }
};