class Solution {
public:
void dfs(vector<vector<int>>&isConnected,int curr,vector<bool>&visited){
    visited[curr]=true;
    for(int i=0 ;i<isConnected.size();i++){
        if(isConnected[curr][i]==1 && !visited[i]){
            dfs(isConnected,i,visited);
    }


}
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<bool>visited(v,false);
        int cnt=0;
        for(int it=0;it<v;it++){
            if(!visited[it]){
        dfs(isConnected,it,visited);
        cnt++;}
        }
        return cnt;
        
    }
};