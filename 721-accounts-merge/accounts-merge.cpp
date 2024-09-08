class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int uu = findPar(u);
        int uv = findPar(v);
        if(uu == uv) return;
        if(rank[uu] < rank[uv]) parent[uu] = uv;
        else if(rank[uu] > rank[uv]) parent[uv] = uu;
        else{
            parent[uu] = uv;
            rank[uv]++;
        }
    }
    void unionBySize(int u,int v){
        int uu = findPar(u);
        int uv = findPar(v);
        if(uu == uv) return;
        if(size[uu] < size[uv]) {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else{
            parent[uv] = uu;
            size[uu]+= size[uv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mpp;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j = 1; j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()) mpp[mail] = i;
                else ds.unionBySize(i,mpp[mail]);
            }
        }
        vector<string> merged[n];
        for(auto it: mpp){
            string mail = it.first;
            int node = ds.findPar(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};