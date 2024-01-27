class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++ ){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findPar(int node){
        if(node == parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionbysize(int u, int v){
        int uu = findPar(u);
        int uv = findPar(v);
        if(uu == uv) return ;
        if(size[uu]<size[uv]){
            parent[uu] = uv;
            size[uv]+= size[uu];
        }
        else{
            parent[uv]=uu;
            size[uu]+=size[uv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int row=0;
        int col=0;
        for(auto it:stones){
            row = max(row,it[0]);
            col = max(col,it[1]);
        }
        DisjointSet ds(row+col+1);
        unordered_map<int,int> stonenode;
        for(auto it:stones){
            int nrow = it[0];
            int ncol  = it[1]+row+1;
            ds.unionbysize(nrow,ncol);
            stonenode[nrow]=1;
            stonenode[ncol]=1;
        }
        int cnt=0;
        for(auto it : stonenode){
            if(ds.findPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};