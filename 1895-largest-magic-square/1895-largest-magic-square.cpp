class Solution {
public:
    bool check(int i,int j, int k, vector<vector<int>>&grid, vector<vector<long long>>&row, vector<vector<long long>>&col){
        long long sum1=0;
        for(int l=0;l<k;l++)sum1 += grid[i+l][j+l];
        long long sum2 =0;
        for(int l=0;l<k;l++) sum2 += grid[i+l][j+k-1-l];
        if(sum2!=sum1)return false;
         for(int l=i; l<i+k; l++) {
            long long sum = row[l][j+k-1];
            if(j > 0) sum -= row[l][j-1];
            if(sum != sum1) return false;
        }
        for(int l=j; l<j+k; l++) {
            long long sum = col[i+k-1][l];
            if(i>0) sum -= col[i-1][l];
            if(sum != sum1) return false;
        }

        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> row(n,vector<long long>(m,0));
        vector<vector<long long>> col(n,vector<long long>(m,0));
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=0;j<m;j++){
                sum += grid[i][j];
                row[i][j] = sum;
            }
        }
        for(int j=0;j<m;j++){
            long long sum=0;
            for(int i=0;i<n;i++){
                sum += grid[i][j];
                col[i][j]=sum;
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=1;i+k <= n && j+k <= m;k++){
                    if(check(i,j,k,grid,row,col)) ans=max(ans,k);
                }
            }
        }
        return ans;
    }
};