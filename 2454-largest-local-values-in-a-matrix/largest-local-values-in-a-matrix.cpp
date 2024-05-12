class Solution {
public:
    bool isValid(int r, int c, int rs,int cs){
        if(r>rs || c>cs) return false;
        return true;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int maxi=0;
        vector<vector<int>> ans(n-2,vector<int> (n-2,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!isValid(i+3,j+3,n,n)) continue;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        maxi = max(maxi,grid[k][l]);
                    }
                }
                ans[i][j]=maxi;
                maxi=0;
            }
        }
        return ans;
    }
};