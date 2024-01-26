class DisjointSet{
public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findPar(int node){
        if(node == parent[node])return node;
        return findPar(parent[node]);
    }
    void unionbysize(int u,int v){
        int uu = findPar(u);
        int uv = findPar(v);
        if(uu == uv)return;
        if (size[uu]<size[uv]){
            parent[uu]=uv;
            size[uv]+=size[uu];
        }
        else{
            parent[uv]=uu;
            size[uu]+=size[uv];
        }
    }
};
class Solution {
private:
    bool check(int nr,int nc,int n){
        return nr>=0 && nr<n && nc>=0 && nc<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int ind=0;ind<4;ind++){
                    int nr = i+dr[ind];
                    int nc = j+dc[ind];
                    if(check(nr,nc,n)&&grid[nr][nc]==1){
                        int nodeno=i*n+j;
                        int adjnode = nr*n+nc;
                        ds.unionbysize(nodeno,adjnode);
                    }
                }
            }
        }
        int a=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int nr = i+dr[ind];
                    int nc = j+dc[ind];
                    if(check(nr,nc,n)){
                        if(grid[nr][nc]==1){
                            components.insert(ds.findPar(nr*n+nc));
                        }
                    }
                }
                int size=0;
                for(auto it:components){
                    size+=ds.size[it];
                }
                a=max(a,size+1);
            }
        }
        for(int i=0;i<n*n;i++ ){
            a=max(a,ds.size[ds.findPar(i)]);
        }
        return a;
    }
};