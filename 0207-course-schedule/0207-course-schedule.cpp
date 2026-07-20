class Solution {
public:
bool dfs(int curr,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&pathvisited){
    visited[curr]=true;
    pathvisited[curr]=true;
    for(auto &x:adj[curr]){
        if(!visited[x]){
            if(dfs(x,adj,visited,pathvisited)==false)return false;
        }
        else if(pathvisited[x]){
            return false;
        }
    }
    pathvisited[curr]=false;
    return true;
   
   
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>visited(numCourses,false);
        vector<bool>pathvisited(numCourses,false);
        for(auto &x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,pathvisited)==false)return false;
            }

        }
        return true;

      
        
    }
};