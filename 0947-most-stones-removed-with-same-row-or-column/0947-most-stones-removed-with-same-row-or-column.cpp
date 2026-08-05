class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(stones[i][0]==stones[j][0] 
                    || stones[i][1]==stones[j][1]){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }

                }

        }
        vector<bool>visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                visited[true];
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int curr=q.front();
                    q.pop();
                    for(auto &it:adj[curr]){
                        if(!visited[it]){
                            visited[it]=true;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return n-cnt;
        
    }
};