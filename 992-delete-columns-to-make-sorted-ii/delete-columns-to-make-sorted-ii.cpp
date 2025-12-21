class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans=0;
        vector<bool>sorted(n-1,false);
        for(int j =0;j<m;j++){
            bool flag=true;
            for(int i=0;i<n-1;i++){
                if(!sorted[i] && strs[i][j] > strs[i+1][j]){
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                ans++;
                continue;
            }
            for(int i=0;i<n-1;i++){
                if(!sorted[i] && strs[i][j] < strs[i+1][j]) sorted[i] = true;
            }
        }
        return ans;
    }
};