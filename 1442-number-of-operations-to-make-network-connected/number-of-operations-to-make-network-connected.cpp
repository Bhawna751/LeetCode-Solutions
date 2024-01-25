class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findpar(int node){
        if(node == parent[node])return node;
        return findpar(parent[node]);
    }
    void unionbysize(int u, int v){
        int uu = findpar(u);
        int uv = findpar(v);
        if(uu == uv)return;
        if(size[uu]<size[uv]){
            parent[uu] = uv;
            size[uv]+=size[uu];
        }
        else{
            parent[uv] = uu;
            size[uu]+=size[uv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt = 0;
        for(auto it : connections){
            int u = it[0];
            int v= it[1];
            if(ds.findpar(u)==ds.findpar(v)){
                cnt++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int cntC=0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                cntC++;
        }
        int ans = cntC-1;
        if(cnt>=ans)return ans;
        return -1;
    }
};