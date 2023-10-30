class Solution {
public:
    void findsubsets(int ind,int n, int k,vector<int> &ds,vector<vector<int>> &ans){
        if(n<0||ds.size()>k)return;
        if(ds.size()==k && n==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<=9;++i){
            ds.push_back(i);
            findsubsets(i+1,n-i,k,ds,ans);
            ds.pop_back();
            }
        }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> ds;
        
        findsubsets(1,n,k,ds,ans);
        return ans;
    }
};