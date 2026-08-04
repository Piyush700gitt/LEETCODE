class disjoint{
    public:

vector<int>parent,size;
disjoint(int n){
    parent.resize(n);
    size.resize(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
}
int ultimateparent(int curr){
    if(curr==parent[curr]){
        return curr;
    }
    return parent[curr]=ultimateparent(parent[curr]);
}
void unionbysize(int u,int v){
    u=ultimateparent(u);
    v=ultimateparent(v);
    if(u==v)return;
    if(size[u]<size[v]){
        parent[u]=v;
        size[v]+=size[u];
    } 
    else{
        parent[v]=u;
        size[u]+=size[v];
    }
}
    

    

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        disjoint ds(n);
        for(auto &it:connections){
            ds.unionbysize(it[0],it[1]);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(ds.ultimateparent(i)==i){
                components++;
            }
        }
        return components-1;
        
    }
};