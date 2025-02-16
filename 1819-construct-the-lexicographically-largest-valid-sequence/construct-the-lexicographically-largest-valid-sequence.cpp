class Solution {
public:
    bool solve(int ind,vector<int>&ans, vector<bool>&num, int n){
        if(ind == ans.size()) return true;
        if(ans[ind]!=0) return solve(ind+1,ans,num,n);
        for(int i=n;i>=1;i--){
            if(num[i])continue;
            num[i]= true;
            ans[ind]=i;
            if(i==1){
                if(solve(ind+1,ans,num,n)) return true;
            }
            else if(ind+i < ans.size() && ans[ind+i] == 0){
                    ans[ind+i] = i;
                if(solve(ind+1,ans,num,n)) return true;
                    ans[ind+i]=0;
            } 
            
            ans[ind]=0;
            num[i]=false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n*2-1,0);
        vector<bool> num(n+1,false);
        solve(0,ans,num,n);
        return ans;
    }
};