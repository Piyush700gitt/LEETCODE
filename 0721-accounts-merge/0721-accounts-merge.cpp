class disjoint {
    vector<int> parent, size;
    public:
    disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int ultimateparent(int curr) {
        if (parent[curr] == curr)
            return curr;
    
    return parent[curr] = ultimateparent(parent[curr]);
    }
    void unionbysize(int u, int v) {
        u=ultimateparent(u);
        v=ultimateparent(v);
        if (u == v)
            return;
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint ds(n);
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    // nhi mila
                    mpp[mail]=i;
                }
                else{
                    // mil gya
                    ds.unionbysize(mpp[mail],i);
                }
            }
        }
        vector<vector<string>>merge(n);
        for(auto &x:mpp){
            string mail=x.first;
            int node=ds.ultimateparent(x.second);
            merge[node].push_back(mail);


        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merge[i].size()==0)continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto &it:merge[i]){
                temp.push_back(it);
                
            }
            ans.push_back(temp);
        }
        return ans;







    }
};