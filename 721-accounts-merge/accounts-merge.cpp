class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet (int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findpar(int node){
        if(node==parent[node])return node;
        return findpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int uu = findpar(u);
        int uv = findpar(v);
        if(uu == uv)return;
        if(size[uu]<size[uv]){
            parent[uu]=uv;
            size[uv] += size[uu];
        }
        else{
            parent[uv]=uu;
            size[uu]+=size[uv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mailNode.find(mail)==mailNode.end()){
                    mailNode[mail]=i;
                }
                else{
                    ds.unionbysize(i,mailNode[mail]);
                }
            }
        }
        vector<string> mergemail[n];
        for(auto it:mailNode){
            string mail = it.first;
            int node = ds.findpar(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i =0;i<n;i++){
            if(mergemail[i].size()==0) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};